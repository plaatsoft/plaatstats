/**
 *  @file
 *  @brief The file contain the PlaatSoft Download Statistics tool
 *  @author wplaat
 *
 *  Copyright (C) 2008-2010 PlaatSoft
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Release Notes
 *
 *  21-03-2010 Version 0.5
 *  - Improve number formatting (Add . after 3 digits).
 *  - Add Windows setup file.
 *  - Add source code to Google Code
 *  - Build PlaatStats with QtCreator v1.3.81. 
 *
 *  18-03-2010 Version 0.4
 *  - Change GUI layout.
 *  - Added Drupal downloads.
 *  - Added application icon.
 *  - Refactor file names.
 *  - Build with QtCreator v1.3.1
 *
 *  17-03-2010 Version 0.3
 *  - First release for Homebrew Scene.
 *  - Cleanup code.
 *  - If internet is down show 0 values in boxes.
 *  - Move clipboard functionality to Menu action.
 *  - Build with QtCreator v1.3.1
 *
 *  16-03-2010 Version 0.2
 *  - Added fix window size.
 *  - Store window position in Windows registry.
 *  - Improve GUI layout.
 *  - Fetch data from Google Code sites.
 *  - When application is started, information is directly fetched.
 *  - Add windows clipboard support (HTML output is added)
 *  - Build with QtCreator v1.3.1
 *
 *  14-03-2010 Version 0.1
 *  - Start building.
 *  - Created GUI.
 *  - Added network call (Plaatsoft and CodeMii website)
 *  - Added stateMachine.
 *  - Build with QtCreator v1.3.1
 */

#include "stats.h"
#include "time.h"
#include "ui_stats.h"

#include <QtGui>
#include <QtNetwork>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readSettings();

    createActions();

    manager = new QNetworkAccessManager(this);
    connect( manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)) );

    // Set fix windows form size.
    setMinimumSize(370,428);
    setMaximumSize(370,428);

    setWindowTitle("PlaatSoft Downloads Statistics v0.5");

    // Fetch direct data from internet.
    fetch();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::createActions()
{
    // Menu actions
    connect(ui->actionRefreshData, SIGNAL(triggered()), this, SLOT(fetch()));
    connect(ui->actionDataClipboard, SIGNAL(triggered()), this, SLOT(fillClipboard()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAbout_QT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About"),
       tr("<b>PlaatSoft Downloads Statistics</b><br>"
          "Version 0.5 (Build 21-03-2010)<br>"
          "<br>"
          "Created by <i>wplaat</i><br>"
          "<br>"
          "This tool collects from several websites the<br>"
          "PlaatSoft download statistics and shows them.<br><br>"
          "All copyrights reserved (c) "
          "<a href='http://www.plaatsoft.nl'>PlaatSoft</a> 2008-2010"));
}

void MainWindow::fillClipboard()
{
    qDebug() << "fillClipboard:enter ";

    QString text = "<table border='1'>" ;
    text += "<tbody>" ;
    text += "<tr>";
    text += "<td><strong>Game</strong></td>";
    text += "<td><strong>PlaatSoft</strong></td>";
    text += "<td><strong>CodeMii</strong></td>";
    text += "<td><strong>Google Code</strong></td>";
    text += "<td><strong>Totals</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>Wii Pong2</td>";
    text += "<td>";
    text += ui->pong2Edit->text();
    text += "</td>";
    text += "<td>";
    text += ui->pong2Edit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->pong2Edit3->text();
    text += "</td>";
    text += "<td>";
    text += ui->pong2Edit4->text();
    text += "</td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>Wii BibleQuiz</td>";
    text += "<td>";
    text += ui->bibleQuizEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->bibleQuizEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->bibleQuizEdit3->text();
    text += "</td>";
    text += "<td>";
    text += ui->bibleQuizEdit4->text();
    text += "</td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>Wii RedSquare</td>";
    text += "<td>";
    text += ui->redSquareEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->redSquareEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->redSquareEdit3->text();
    text += "</td>";
    text += "<td>";
    text += ui->redSquareEdit4->text();
    text += "</td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>Wii SpaceBubble</td>";
    text += "<td>";
    text += ui->spaceBubbleEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->spaceBubbleEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->spaceBubbleEdit3->text();
    text += "</td>";
    text += "<td>";
    text += ui->spaceBubbleEdit4->text();
    text += "</td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>Wii TowerDefense</td>";
    text += "<td>";
    text += ui->towerDefenseEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->towerDefenseEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->towerDefenseEdit3->text();
    text += "</td>";
    text += "<td>";
    text += ui->towerDefenseEdit4->text();
    text += "</td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td><strong>Totals</strong></td>";
    text += "<td><strong>";
    text += ui->totals->text();
    text += "</strong></td>";
    text += "<td><strong>";
    text += ui->totals2->text();
    text += "</strong></td>";
    text += "<td><strong>";
    text += ui->totals3->text();
    text += "</strong></td>";
    text += "<td><strong>";
    text += ui->totals4->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "</tbody>";
    text += "</table>";

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(text);
}

void MainWindow::fetch()
{
    // Clear data
    ui->pong2Edit->setText("");
    ui->pong2Edit2->setText("");
    ui->pong2Edit3->setText("");
    ui->pong2Edit4->setText("");

    ui->bibleQuizEdit->setText("");
    ui->bibleQuizEdit2->setText("");
    ui->bibleQuizEdit3->setText("");
    ui->bibleQuizEdit4->setText("");

    ui->redSquareEdit->setText("");
    ui->redSquareEdit2->setText("");
    ui->redSquareEdit3->setText("");
    ui->redSquareEdit4->setText("");

    ui->spaceBubbleEdit->setText("");
    ui->spaceBubbleEdit2->setText("");
    ui->spaceBubbleEdit3->setText("");
    ui->spaceBubbleEdit4->setText("");

    ui->towerDefenseEdit->setText("");
    ui->towerDefenseEdit2->setText("");
    ui->towerDefenseEdit3->setText("");
    ui->towerDefenseEdit4->setText("");

    ui->totals->setText("");
    ui->totals2->setText("");
    ui->totals3->setText("");
    ui->totals4->setText("");

    ui->addressbookEdit1->setText("");
    ui->eventNotificationEdit1->setText("");
    ui->churchEdit1->setText("");
    ui->totalsDrupalEdit1->setText("");

    // Disable button during request.
    ui->actionRefreshData->setEnabled(false);

    // Show datestamp when latest fetch ocure!
    //ui->timeStampLabel->setText(getDate());

    // Start startmachine
    sm=0;
    stateMachine();
}

void MainWindow::stateMachine()
{
    QString address;
    qDebug() << "stateMachine:enter " << sm;

    switch (sm)
    {
      case 0: {
                address = QString("http://www.plaatsoft.nl/wiibrew/statistics/");
                qDebug() << "Fetch " << address;
                manager->get(QNetworkRequest(address));
                sm++;
              }
              break;

      case 1: {
                bool ok;

                // Parse Information
                int j = result.indexOf("Pong2.zip",0);
                QString t = result.mid(j,80);
                QString tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "Pong2 download =" << tmp;
                ui->pong2Edit->setText(tmp);

                j = result.indexOf("bibleQuiz.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "bibleQuiz.zip download =" << tmp;
                ui->bibleQuizEdit->setText(tmp);

                j = result.indexOf("RedSquare.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "RedSquare.zip download =" << tmp;
                ui->redSquareEdit->setText(tmp);

                j = result.indexOf("SpaceBubble.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "SpaceBubble.zip download =" << tmp;
                ui->spaceBubbleEdit->setText(tmp);
 
                j = result.indexOf("TowerDefense.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "TowerDefense.zip download =" << tmp;
                ui->towerDefenseEdit->setText(tmp);
                
                int sum=0;
                j = result.indexOf("addressbook-v4.x.zip",0);
                t = result.mid(j+20,80);
                qDebug() << "addressbook-v4.x.zip download =" << tmp;
                tmp = t.mid(t.indexOf("-")+2,3).replace(",",".");
                 qDebug() << "addressbook-v4.x.zip download =" << tmp;
                sum += tmp.toInt(&ok, 10);

                j = result.indexOf("addressbook-v5.x.zip",0);
                t = result.mid(j+20,80);
                tmp = t.mid(t.indexOf("-")+2,3).replace(",",".");
                sum += tmp.toInt(&ok, 10);

                j = result.indexOf("addressbook-v6.x.zip",0);
                t = result.mid(j+20,80);
                tmp = t.mid(t.indexOf("-")+2,3).replace(",",".");
                sum += tmp.toInt(&ok, 10);

                ui->addressbookEdit1->setText(QString::number(sum));

                sum=0;
                j = result.indexOf("event_notification-v4.x.zip",0);
                t = result.mid(j+20,80);
                tmp = t.mid(t.indexOf("-")+2,3).replace(",",".");
                sum += tmp.toInt(&ok, 10);

                j = result.indexOf("event_notification-v5.x.zip",0);
                t = result.mid(j+20,80);
                tmp = t.mid(t.indexOf("-")+2,3).replace(",",".");
                sum += tmp.toInt(&ok, 10);

                j = result.indexOf("event_notification-v6.x.zip",0);
                t = result.mid(j+20,80);
                tmp = t.mid(t.indexOf("-")+2,3).replace(",",".");
                sum += tmp.toInt(&ok, 10);

                ui->eventNotificationEdit1->setText(QString::number(sum));

                sum=0;
                j = result.indexOf("ChurchAdministration-v5.x.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                sum += tmp.toInt(&ok, 10);

                ui->churchEdit1->setText(QString::number(sum));

                address = QString("http://www.codemii.com/hbbstats.php");
                qDebug() << "Fetch " << address;
                manager->get(QNetworkRequest(address));

                calculate();
                sm++;
             }
             break;

     case 2: {
               // Parse Information
               int j = result.indexOf("pong2",0);
               QString t = result.mid(j+20,120);
               int k = t.indexOf("<font face='Arial'>");
               int l = t.indexOf("</font>");
               QString tmp = t.mid(k+19,(l-(k+19)));
               if (tmp.size()==0) tmp="0";
               qDebug() << "Pong2 download =" << tmp;
               ui->pong2Edit2->setText(formatNumber(tmp));

               j = result.indexOf("bibleQuiz",0);
               t = result.mid(j+20,120);
               k = t.indexOf("<font face='Arial'>");
               l = t.indexOf("</font>");
               tmp = t.mid(k+19,(l-(k+19)));
               if (tmp.size()==0) tmp="0";
               qDebug() << "bibleQuiz download =" << tmp;
               ui->bibleQuizEdit2->setText(formatNumber(tmp));

               j = result.indexOf("RedSquare",0);
               t = result.mid(j+20,120);
               k = t.indexOf("<font face='Arial'>");
               l = t.indexOf("</font>");
               tmp = t.mid(k+19,(l-(k+19)));
               if (tmp.size()==0) tmp="0";
               qDebug() << "RedSquare download =" << tmp;
               ui->redSquareEdit2->setText(formatNumber(tmp));

               j = result.indexOf("SpaceBubble",0);
               t = result.mid(j+20,120);
               k = t.indexOf("<font face='Arial'>");
               l = t.indexOf("</font>");
               tmp = t.mid(k+19,(l-(k+19)));
               if (tmp.size()==0) tmp="0";
               qDebug() << "SpaceBubble download =" << tmp;
               ui->spaceBubbleEdit2->setText(formatNumber(tmp));

               j = result.indexOf("TowerDefense",0);
               t = result.mid(j+20,120);
               k = t.indexOf("<font face='Arial'>");
               l = t.indexOf("</font>");
               tmp = t.mid(k+19,(l-(k+19)));
               if (tmp.size()==0) tmp="0";
               qDebug() << "TowerDefense download =" << tmp;
               ui->towerDefenseEdit2->setText(formatNumber(tmp));

               address = QString("http://code.google.com/p/pongtwo/downloads/list");
               qDebug() << "Fetch " << address;
               manager->get(QNetworkRequest(address));

               calculate();
               sm++;
             }
             break;

     case 3: {
               // Get Pong2 Google code download
               bool ok;
               int sum=0;
               int j = result.indexOf("vt col_4",0);
               QString buffer(result);
               do {
                 j+=190;
                 qDebug() << "j=" << j;
                 QString t = buffer.mid(j,50);
                 qDebug() << "t=" << t;
                 int k = t.indexOf(">");
                 qDebug() << "k=" << k;
                 QString tmp = t.mid(k+1,8).simplified();
                 sum += tmp.toInt(&ok, 10);
                 qDebug() << "sum =" << sum;                 
                 buffer = buffer.mid(j);
                 qDebug() << "buffer size =" << buffer.size();
                 j = buffer.indexOf("vt col_4",0);
               } while (j!=-1);

               qDebug() << "Pong2 download =" << sum;
               ui->pong2Edit3->setText(formatNumber(sum));

               address = QString("http://code.google.com/p/biblequiz/downloads/list");
               qDebug() << "Fetch " << address;
               manager->get(QNetworkRequest(address));

               calculate();
               sm++;
             }
             break;

    case 4: {
              // Get BibleQuiz Google code download
              bool ok;
              int sum=0;
              int j = result.indexOf("vt col_4",0);
              QString buffer(result);
              do {
                j+=190;
                qDebug() << "j=" << j;
                QString t = buffer.mid(j,50);
                qDebug() << "t=" << t;
                int k = t.indexOf(">");
                qDebug() << "k=" << k;
                QString tmp = t.mid(k+1,8).simplified();
                sum += tmp.toInt(&ok, 10);
                qDebug() << "sum =" << sum;
                buffer = buffer.mid(j);
                qDebug() << "buffer size =" << buffer.size();
                j = buffer.indexOf("vt col_4",0);
              } while (j!=-1);

              qDebug() << "BibleQuiz download =" << sum;
              ui->bibleQuizEdit3->setText(formatNumber(sum));

              address = QString("http://code.google.com/p/redsquare/downloads/list");
              qDebug() << "Fetch " << address;
              manager->get(QNetworkRequest(address));

              calculate();
              sm++;
            }
            break;

    case 5: {
              // Get RedSquare Google code download
              bool ok;
              int sum=0;
              int j = result.indexOf("vt col_4",0);
              QString buffer(result);
              do {
                j+=190;
                qDebug() << "j=" << j;
                QString t = buffer.mid(j,50);
                qDebug() << "t=" << t;
                int k = t.indexOf(">");
                qDebug() << "k=" << k;
                QString tmp = t.mid(k+1,8).simplified();
                sum += tmp.toInt(&ok, 10);
                qDebug() << "sum =" << sum;
                buffer = buffer.mid(j);
                qDebug() << "buffer size =" << buffer.size();
                j = buffer.indexOf("vt col_4",0);
              } while (j!=-1);

              qDebug() << "RedSquare download =" << sum;
              ui->redSquareEdit3->setText(formatNumber(sum));

              address = QString("http://code.google.com/p/spacebubble/downloads/list");
              qDebug() << "Fetch " << address;
              manager->get(QNetworkRequest(address));

              calculate();
              sm++;
            }
            break;

    case 6: {
              // Get SpaceBubble Google code download
              bool ok;
              int sum=0;
              int j = result.indexOf("vt col_4",0);
              QString buffer(result);
              do {
                j+=190;
                qDebug() << "j=" << j;
                QString t = buffer.mid(j,50);
                qDebug() << "t=" << t;
                int k = t.indexOf(">");
                qDebug() << "k=" << k;
                QString tmp = t.mid(k+1,8).simplified();
                sum += tmp.toInt(&ok, 10);
                qDebug() << "sum =" << sum;
                buffer = buffer.mid(j);
                qDebug() << "buffer size =" << buffer.size();
                j = buffer.indexOf("vt col_4",0);
              } while (j!=-1);

              qDebug() << "SpaceBubble download =" << sum;
              ui->spaceBubbleEdit3->setText(formatNumber(sum));

              address = QString("http://code.google.com/p/wiitowerdefense/downloads/list");
              qDebug() << "Fetch " << address;
              manager->get(QNetworkRequest(address));

              calculate();
              sm++;
            }
            break;

    case 7: {
              // Get TowerDefense Google code download
              bool ok;
              int sum=0;
              int j = result.indexOf("vt col_4",0);
              QString buffer(result);
              do {
                j+=190;
                qDebug() << "j=" << j;
                QString t = buffer.mid(j,50);
                qDebug() << "t=" << t;
                int k = t.indexOf(">");
                qDebug() << "k=" << k;
                QString tmp = t.mid(k+1,8).simplified();
                sum += tmp.toInt(&ok, 10);
                qDebug() << "sum =" << sum;
                buffer = buffer.mid(j);
                qDebug() << "buffer size =" << buffer.size();
                j = buffer.indexOf("vt col_4",0);
              } while (j!=-1);

              qDebug() << "TowerDefense download =" << sum;
              ui->towerDefenseEdit3->setText(formatNumber(sum));

              ui->actionRefreshData->setEnabled(true);
              calculate();

              sm++;
            }
            break;
    }
}

void MainWindow::calculate()
{
    calculateApplTotals();
    calculateWebsite();
    calculateHomebrewBrowser();
    calculateGoogleCode();
    calculateDrupalTotals();
    calculateWiiTotals();
}

void MainWindow::calculateApplTotals()
{
   int a = convert(ui->pong2Edit->text());
   int b = convert(ui->pong2Edit2->text());
   int c = convert(ui->pong2Edit3->text());
   ui->pong2Edit4->setText(formatNumber(a+b+c));

   a = convert(ui->bibleQuizEdit->text());
   b = convert(ui->bibleQuizEdit2->text());
   c = convert(ui->bibleQuizEdit3->text());
   ui->bibleQuizEdit4->setText(formatNumber(a+b+c));

   a = convert(ui->redSquareEdit->text());
   b = convert(ui->redSquareEdit2->text());
   c = convert(ui->redSquareEdit3->text());
   ui->redSquareEdit4->setText(formatNumber(a+b+c));

   a = convert(ui->spaceBubbleEdit->text());
   b = convert(ui->spaceBubbleEdit2->text());
   c = convert(ui->spaceBubbleEdit3->text());
   ui->spaceBubbleEdit4->setText(formatNumber(a+b+c));

   a = convert(ui->towerDefenseEdit->text());
   b = convert(ui->towerDefenseEdit2->text());
   c = convert(ui->towerDefenseEdit3->text());
   ui->towerDefenseEdit4->setText(formatNumber(a+b+c));
}

void MainWindow::calculateWebsite()
{
   int a = convert(ui->pong2Edit->text());
   int b = convert(ui->bibleQuizEdit->text());
   int c = convert(ui->redSquareEdit->text());
   int d = convert(ui->spaceBubbleEdit->text());
   int e = convert(ui->towerDefenseEdit->text());
   ui->totals->setText(formatNumber(a+b+c+d+e));
}

void MainWindow::calculateHomebrewBrowser()
{
   int a = convert(ui->pong2Edit2->text());
   int b = convert(ui->bibleQuizEdit2->text());
   int c = convert(ui->redSquareEdit2->text());
   int d = convert(ui->spaceBubbleEdit2->text());
   int e = convert(ui->towerDefenseEdit2->text());
   ui->totals2->setText(formatNumber(a+b+c+d+e));
}

void MainWindow::calculateGoogleCode()
{
   int a = convert(ui->pong2Edit3->text());
   int b = convert(ui->bibleQuizEdit3->text());
   int c = convert(ui->redSquareEdit3->text());
   int d = convert(ui->spaceBubbleEdit3->text());
   int e = convert(ui->towerDefenseEdit3->text());
   ui->totals3->setText(formatNumber(a+b+c+d+e));
}

void MainWindow::calculateWiiTotals()
{
   int a = convert(ui->pong2Edit4->text());
   int b = convert(ui->bibleQuizEdit4->text());
   int c = convert(ui->redSquareEdit4->text());
   int d = convert(ui->spaceBubbleEdit4->text());
   int e = convert(ui->towerDefenseEdit4->text());
   ui->totals4->setText(formatNumber(a+b+c+d+e));
}

void MainWindow::calculateDrupalTotals()
{
   int a = convert(ui->addressbookEdit1->text());
   int b = convert(ui->eventNotificationEdit1->text());
   int c = convert(ui->churchEdit1->text());
   ui->totalsDrupalEdit1->setText(formatNumber(a+b+c));
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QString sA = QString::number( reply->bytesAvailable());
    result = reply->readAll();

    qDebug() << "Request " << sm << "Bytes received " << sA;

    // Request received, go back to statemachine to analyse information.
    stateMachine();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
   // Store current window position
   writeSettings();
}

void MainWindow::readSettings()
{
    // Fetch previous window position
    QSettings settings("PlaatSoft", "Statistics");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    move(pos);
}

void MainWindow::writeSettings()
{
    // Store current window position
    QSettings settings("PlaatSoft", "Statistics");
    settings.setValue("pos", pos());
}

int MainWindow::convert(QString number)
{
   bool ok;

   // Remove . character before converting to number.
   return number.replace(".","").toInt(&ok, 10);
}

QString MainWindow::formatNumber(int number)
{
    QString tmp = QString::number(number);

    // Insert . character after 3 digits
    int len = tmp.size();
    if (len>3) {
        return tmp.insert(len-3,".");
    } else {
        return tmp;
    }
}

QString MainWindow::formatNumber(QString number)
{
    // Insert . character after 3 digits
    int len = number.size();
    if (len>3) {
        return number.insert(len-3,".");
    } else {
        return number;
    }
}

/**
 * Create trace timestamp
 *
 * @return timestamp in dutch format
 */
const char * MainWindow::getDate()
{
  struct tm *now = NULL;
  time_t time_value = 0;
  static char buf[ 50 ] ;

  /* Get time value */
  time_value = time(NULL);

  /* Get time and date structure */
  now = localtime(&time_value);

  // Create time stamp
  sprintf(buf,"Last update: %02d-%02d-%04d %02d:%02d:%02d",
        now->tm_mday, now->tm_mon+1, now->tm_year+1900,
        now->tm_hour,now->tm_min,now->tm_sec);

  return buf;
}
