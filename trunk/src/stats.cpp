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
 */

#include <QtGui>
#include <QtNetwork>

#include "stats.h"
#include "about.h"
#include "settings.h"
#include "time.h"
#include "ui_stats.h"


// ---------------------------------------------------
// Constructor & Destructor
// ---------------------------------------------------

/**
 * Constructor
 */
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

    setWindowTitle(tr("PlaatSoft Statistics " VERSION));

    // Fetch direct data from internet.
    fetchData();
}

/**
 * Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------------------------------------------
// Other methods
// ---------------------------------------------------

/**
 * Change Event
 */
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

/**
 * Create Actions
 */
void MainWindow::createActions()
{
    // Menu actions
    connect(ui->actionRefreshData, SIGNAL(triggered()), this, SLOT(fetchData()));
    connect(ui->actionDataClipboard, SIGNAL(triggered()), this, SLOT(fillClipboard()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

/**
 * Fill Clipboard
 */
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

/**
 * Parse data for version information
 */
void MainWindow::parseVersion(QString response)
{
   qDebug() << response;

   QString text;
   int pos = response.indexOf("Version ");
   QString version = response.mid(pos+8,4).simplified();
   if ((version.size()>0) && (version.compare(VERSION)!=0))
   {
       text="New version ";
       text+=version;
       text+=" of PlaatStats is available!<br>";
       text+="Check out http://www.plaatsoft.nl for more information.";

       QMessageBox::information(this, tr("Software update"),text);
   } else {
       text = "Update check failed!";
       QMessageBox::warning(this, tr("Warning"),text);
   }

   ui->actionRefreshData->setEnabled(true);
   ui->actionCheck_for_update->setEnabled(true);
}

/**
 * fetchData
 * Network Request
 */
void MainWindow::fetchData()
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
    ui->actionCheck_for_update->setEnabled(false);

    // Start startmachine
    sm=0;
    stateMachine();
}

/**
 * Create http request for version data.
 */
void MainWindow::fetchVersion()
{
    QSettings qSettings("PlaatSoft", "PlaatStats");

    // Proxy support
    bool enabled = qSettings.value("proxyEnabled",false).toBool();
    QNetworkProxy proxy;
    if (enabled)
    {
        qDebug() << "Proxy enabled";
        bool ok;
        proxy.setUser(qSettings.value("loginName","").toString());
        proxy.setPassword(settings.decrypt(qSettings.value("password","").toString()));
        proxy.setPort(qSettings.value("proxyPort","").toString().toInt(&ok, 10));
        proxy.setHostName(qSettings.value("proxyAddress","").toString());
        proxy.setType(QNetworkProxy::HttpProxy);
    } else {
        proxy.setType(QNetworkProxy::NoProxy);
    }
    manager->setProxy(proxy);

    QNetworkRequest request;
    request.setUrl(QUrl("http://www.plaatsoft.nl/service/plaatstats.html"));

    manager->get(request);

    // StateMachine 10 event
    sm=10;

    // Disable button during request.
    ui->actionRefreshData->setEnabled(false);
    ui->actionCheck_for_update->setEnabled(false);
}

/**
 * StateMachine
 */
void MainWindow::stateMachine()
{
    QString address;
    qDebug() << "stateMachine:enter " << sm;

    QSettings qSettings("PlaatSoft", "PlaatStats");

    // Proxy support
    bool enabled = qSettings.value("proxyEnabled",false).toBool();
    QNetworkProxy proxy;
    if (enabled)
    {
        qDebug() << "Proxy enabled";
        bool ok;
        proxy.setUser(qSettings.value("loginName","").toString());
        proxy.setPassword(settings.decrypt(qSettings.value("password","").toString()));
        proxy.setPort(qSettings.value("proxyPort","").toString().toInt(&ok, 10));
        proxy.setHostName(qSettings.value("proxyAddress","").toString());
        proxy.setType(QNetworkProxy::HttpProxy);
    } else {
        proxy.setType(QNetworkProxy::NoProxy);
    }
    manager->setProxy(proxy);

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
              ui->actionCheck_for_update->setEnabled(true);
              calculate();

              sm++;
            }
            break;

        case 10:
            {
                // New version control
                parseVersion(result);
            }
            break;
    }
}

/**
 * Calculate
 */
void MainWindow::calculate()
{
    calculateApplTotals();
    calculateWebsite();
    calculateHomebrewBrowser();
    calculateGoogleCode();
    calculateDrupalTotals();
    calculateWiiTotals();
}

/**
 * Calculate Application totals
 */
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

/**
 * Calculate My Website totals
 */
void MainWindow::calculateWebsite()
{
   int a = convert(ui->pong2Edit->text());
   int b = convert(ui->bibleQuizEdit->text());
   int c = convert(ui->redSquareEdit->text());
   int d = convert(ui->spaceBubbleEdit->text());
   int e = convert(ui->towerDefenseEdit->text());
   ui->totals->setText(formatNumber(a+b+c+d+e));
}

/**
 * Calculate CodeMii totals
 */
void MainWindow::calculateHomebrewBrowser()
{
   int a = convert(ui->pong2Edit2->text());
   int b = convert(ui->bibleQuizEdit2->text());
   int c = convert(ui->redSquareEdit2->text());
   int d = convert(ui->spaceBubbleEdit2->text());
   int e = convert(ui->towerDefenseEdit2->text());
   ui->totals2->setText(formatNumber(a+b+c+d+e));
}

/**
 * Calculate Google Code totals
 */
void MainWindow::calculateGoogleCode()
{
   int a = convert(ui->pong2Edit3->text());
   int b = convert(ui->bibleQuizEdit3->text());
   int c = convert(ui->redSquareEdit3->text());
   int d = convert(ui->spaceBubbleEdit3->text());
   int e = convert(ui->towerDefenseEdit3->text());
   ui->totals3->setText(formatNumber(a+b+c+d+e));
}

/**
 * Calculate Wii totals
 */

void MainWindow::calculateWiiTotals()
{
   int a = convert(ui->pong2Edit4->text());
   int b = convert(ui->bibleQuizEdit4->text());
   int c = convert(ui->redSquareEdit4->text());
   int d = convert(ui->spaceBubbleEdit4->text());
   int e = convert(ui->towerDefenseEdit4->text());
   ui->totals4->setText(formatNumber(a+b+c+d+e));
}

/**
 * Calculate Drupals totals
 */
void MainWindow::calculateDrupalTotals()
{
   int a = convert(ui->addressbookEdit1->text());
   int b = convert(ui->eventNotificationEdit1->text());
   int c = convert(ui->churchEdit1->text());
   ui->totalsDrupalEdit1->setText(formatNumber(a+b+c));
}

/**
 * Process request HTTP response.
 */
void MainWindow::replyFinished(QNetworkReply *reply)
{
    QString sA = QString::number( reply->bytesAvailable());
    result = reply->readAll();

    qDebug() << "Request " << sm << "Bytes received " << sA;

    // Request received, go back to statemachine to analyse information.
    stateMachine();
}

/**
 * Read settings out Windows registry
 */
void MainWindow::readSettings()
{
    // Fetch previous window position
    QSettings settings("PlaatSoft", "PlaatStats");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    move(pos);
}

/**
 * Write settings to Windows registry
 */
void MainWindow::writeSettings()
{
    // Store current window position
    QSettings settings("PlaatSoft", "PlaatStats");
    settings.setValue("pos", pos());
}

/**
 * Convert String to number
 */
int MainWindow::convert(QString number)
{
   bool ok;

   // Remove . character before converting to number.
   return number.replace(".","").toInt(&ok, 10);
}

/**
 * Format number
 */
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

/**
 * Format number
 */
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

// ---------------------------------------------------
// User Actions
// ---------------------------------------------------

/**
 * Close Window
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
   // Store current window position
   writeSettings();
}

/**
 * Show about window
 */
void MainWindow::showAbout()
{
    // Set settings window position related to Main window.
    QPoint position = QPoint(pos());
    position.setX(position.x()-80);
    position.setY(position.y()+100);
    about.move(position);

    // Disable Man window
    setDisabled(true);

    // Make about window visible
    about.show();
}

void MainWindow::on_actionSettings_triggered()
{
    // Set settings window position related to Main window.
    QPoint position = QPoint(pos());
    position.setX(position.x()-10);
    position.setY(position.y()+120);
    settings.move(position);

    // Disable Man window
    setDisabled(true);

    // Make settings window visible
    settings.show();
}

void MainWindow::on_actionCheck_for_update_triggered()
{
   fetchVersion();
}

// ---------------------------------------------------
// The End
// ---------------------------------------------------

