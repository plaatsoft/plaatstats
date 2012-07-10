/**
 *  @file
 *  @brief The file contain the PlaatSoft Download Statistics tool
 *  @author wplaat
 *
 *  Copyright (C) 2008-2012 PlaatSoft
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
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    readSettings();

    createActions();

    manager = new QNetworkAccessManager(this);
    connect( manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)) );

    // Set fix windows form size.
    setMinimumSize(370,503);
    setMaximumSize(370,503);

    setWindowTitle(tr("PlaatSoft Statistics " VERSION));

    // Fetch direct data from internet.
    fetchData();
}

/**
 * Destructor
 */
MainWindow::~MainWindow() {

    delete ui;
}

// ---------------------------------------------------
// Other methods
// ---------------------------------------------------

/**
 * Change Event
 */
void MainWindow::changeEvent(QEvent *e) {

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
    text += "<td><strong>Nintendo Wii</strong></td>";
    text += "<td><strong>PlaatSoft</strong></td>";
    text += "<td><strong>CodeMii</strong></td>";
    text += "<td><strong>Google Code</strong></td>";
    text += "<td><strong>Totals</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>Pong2</td>";
    text += "<td>";
    text += ui->pong2Edit->text();
    text += "</td>";
    text += "<td>";
    text += ui->pong2Edit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->pong2Edit3->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->pong2Edit4->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>BibleQuiz</td>";
    text += "<td>";
    text += ui->bibleQuizEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->bibleQuizEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->bibleQuizEdit3->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->bibleQuizEdit4->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>RedSquare</td>";
    text += "<td>";
    text += ui->redSquareEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->redSquareEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->redSquareEdit3->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->redSquareEdit4->text();
    text += "<strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>SpaceBubble</td>";
    text += "<td>";
    text += ui->spaceBubbleEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->spaceBubbleEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->spaceBubbleEdit3->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->spaceBubbleEdit4->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>TowerDefense</td>";
    text += "<td>";
    text += ui->towerDefenseEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->towerDefenseEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->towerDefenseEdit3->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->towerDefenseEdit4->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>KnightsQuest</td>";
    text += "<td>";
    text += ui->KnightsQuestEdit->text();
    text += "</td>";
    text += "<td>";
    text += ui->KnightsQuestEdit2->text();
    text += "</td>";
    text += "<td>";
    text += ui->KnightsQuestEdit3->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->KnightsQuestEdit4->text();
    text += "</strong></td>";
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
    text += char(13);
    text += char(10);

    // ---------------------------------------------

    text += "<table border='1'>" ;
    text += "<tbody>" ;
    text += "<tr>";
    text += "<td><strong>Drupal</strong></td>";
    text += "<td><strong>PlaatSoft</strong></td>";
    text += "<td><strong>Google Code</strong></td>";
    text += "<td><strong>Totals</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>Addressbook</td>";
    text += "<td>";
    text += ui->addressbookEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->addressbookEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->addressbookEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>EventNotification</td>";
    text += "<td>";
    text += ui->eventNotificationEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->eventNotificationEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->eventNotificationEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>ChurchAdminstration</td>";
    text += "<td>";
    text += ui->churchEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->churchEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->churchEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td><strong>Totals</strong></td>";
    text += "<td><strong>";
    text += ui->totalsDrupalEdit1->text();
    text += "</strong></td>";
    text += "<td><strong>";
    text += ui->totalsDrupalEdit2->text();
    text += "</strong></td>";
    text += "<td><strong>";
    text += ui->totalsDrupalEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "</tbody>";
    text += "</table>";
    text += char(13);
    text += char(10);

    // ---------------------------------------------

    text += "<table border='1'>" ;
    text += "<tbody>" ;
    text += "<tr>";
    text += "<td><strong>Windows</strong></td>";
    text += "<td><strong>PlaatSoft</strong></td>";
    text += "<td><strong>Google Code</strong></td>";
    text += "<td><strong>Totals</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>PlaatStats</td>";
    text += "<td>";
    text += ui->plaatstatsEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->plaatstatsEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->plaatstatsEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>PlaatScore</td>";
    text += "<td>";
    text += ui->plaatscoreEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->plaatscoreEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->plaatscoreEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>RedSquare</td>";
    text += "<td>";
    text += ui->winredsquareEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->winredsquareEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->winredsquareEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>KnightsQuest</td>";
    text += "<td>";
    text += ui->winKnightsQuestEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->winKnightsQuestEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->winKnightsQuestEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>ChatCostCalc</td>";
    text += "<td>";
    text += ui->winChatCostCalcEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->winChatCostCalcEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->winChatCostCalcEdit3->text();
    text += "</strong></td>";
    text += "</tr>";

    text += "<tr>";
    text += "<td>WarQuest</td>";
    text += "<td>";
    text += ui->winWarQuestClientEdit1->text();
    text += "</td>";
    text += "<td>";
    text += ui->winWarQuestClientEdit2->text();
    text += "</td>";
    text += "<td><strong>";
    text += ui->winWarQuestClientEdit3->text();
    text += "</strong></td>";
    text += "</tr>";



    text += "<tr>";
    text += "<td><strong>Totals</strong></td>";
    text += "<td><strong>";
    text += ui->totalsWindowsEdit1->text();
    text += "</strong></td>";
    text += "<td><strong>";
    text += ui->totalsWindowsEdit2->text();
    text += "</strong></td>";
    text += "<td><strong>";
    text += ui->totalsWindowsEdit3->text();
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
   qDebug() << "Version = [" << version << "]";

   if (version.size()>0) {

       if (version.compare(VERSION)!=0) {
            text="New version ";
            text+=version;
            text+=" of PlaatStats is available!<br>";
            text+="Check out http://www.plaatsoft.nl for more information.";
        } else {
            text="No update available!";
        }
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
void MainWindow::fetchData() {

    // Clear data

    // -- WII MODULES ----

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

    ui->KnightsQuestEdit->setText("");
    ui->KnightsQuestEdit2->setText("");
    ui->KnightsQuestEdit3->setText("");
    ui->KnightsQuestEdit4->setText("");

    ui->totals->setText("");
    ui->totals2->setText("");
    ui->totals3->setText("");
    ui->totals4->setText("");

    // -- DRUPAL MODULES ----

    ui->addressbookEdit1->setText("");
    ui->addressbookEdit2->setText("");
    ui->addressbookEdit3->setText("");

    ui->eventNotificationEdit1->setText("");
    ui->eventNotificationEdit2->setText("");
    ui->eventNotificationEdit3->setText("");

    ui->churchEdit1->setText("");
    ui->churchEdit2->setText("");
    ui->churchEdit3->setText("");

    ui->totalsDrupalEdit1->setText("");
    ui->totalsDrupalEdit2->setText("");
    ui->totalsDrupalEdit3->setText("");

    // -- WINDOWS MODULES ----

    ui->plaatstatsEdit1->setText("");
    ui->plaatstatsEdit2->setText("");
    ui->plaatstatsEdit3->setText("");

    ui->plaatscoreEdit1->setText("");
    ui->plaatscoreEdit2->setText("");
    ui->plaatscoreEdit3->setText("");

    ui->winredsquareEdit1->setText("");
    ui->winredsquareEdit2->setText("");
    ui->winredsquareEdit3->setText("");

    ui->winKnightsQuestEdit1->setText("");
    ui->winKnightsQuestEdit2->setText("");
    ui->winKnightsQuestEdit3->setText("");

    ui->winChatCostCalcEdit1->setText("");
    ui->winChatCostCalcEdit2->setText("");
    ui->winChatCostCalcEdit3->setText("");

    ui->winWarQuestClientEdit1->setText("");
    ui->winWarQuestClientEdit2->setText("");
    ui->winWarQuestClientEdit3->setText("");

    ui->totalsWindowsEdit1->setText("");
    ui->totalsWindowsEdit2->setText("");
    ui->totalsWindowsEdit3->setText("");

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
void MainWindow::fetchVersion() {

    QSettings qSettings("PlaatSoft", "PlaatStats");

    // Proxy support
    bool enabled = qSettings.value("proxyEnabled",false).toBool();
    QNetworkProxy proxy;
    if (enabled)
    {
        qDebug() << "Proxy enabled";
        bool ok;
        QString login = qSettings.value("loginName","").toString();
        //qDebug() << "login=" << login;
        if (login.length()>0)
        {
            proxy.setUser(login);
        }
        QString password = settings.decrypt(qSettings.value("password","").toString());
        //qDebug() << "password=" << password;
        if (password.length()>0)
        {
            proxy.setPassword(password);
        }
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

    // StateMachine 20 event
    sm=20;

    // Disable button during request.
    ui->actionRefreshData->setEnabled(false);
    ui->actionCheck_for_update->setEnabled(false);
}

int MainWindow::parseGoogleCodePage(QString result) {

   bool ok;
   int sum=0;
   int j;
   QString tmp;
   QString buffer(result);

   do {
      j = buffer.indexOf("<td class=\"vt col_5\"",0);
      qDebug() << "j=" << j;
      tmp = buffer.mid(j,400);
      //qDebug() << "tmp=" << tmp;
      tmp = tmp.replace( QRegExp("<[^>]*>"), "" ).trimmed();
      //qDebug() << "tmp=" << tmp;
      sum += tmp.left(5).toInt(&ok, 10);
      qDebug() << "sum=" << sum;
      buffer = buffer.mid(j+1);
      //qDebug() << "buffer=" << buffer;
   } while (j!=-1);

   return sum;
}

/**
 * StateMachine
 */
void MainWindow::stateMachine() {
    QString address;
    qDebug() << "stateMachine:enter " << sm;

    QSettings qSettings("PlaatSoft", "PlaatStats");

    // Proxy support
    bool enabled = qSettings.value("proxyEnabled",false).toBool();
    QNetworkProxy proxy;
    if (enabled)
    {
        QNetworkProxyQuery npq(QUrl("http://www.google.com"));
        QList<QNetworkProxy> listOfProxies = QNetworkProxyFactory::systemProxyForQuery(npq);

        qDebug() << "Proxy enabled";
        bool ok;
        QString login = qSettings.value("loginName","").toString();
        //qDebug() << "login=" << login;
        if (login.length()>0)
        {
            proxy.setUser(login);
        }
        QString password = settings.decrypt(qSettings.value("password","").toString());
        //qDebug() << "password=" << password;
        if (password.length()>0)
        {
            proxy.setPassword(password);
        }

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
                address = QString("http://www.plaatsoft.nl/statistics/");
                qDebug() << "Fetch " << address;
                manager->get(QNetworkRequest(address));
                sm++;
              }
              break;

      case 1: {
                bool ok;

                // --- Wii software ---

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

                j = result.indexOf("KnightsQuest.zip",0);
                if (j!=-1) {
                  t = result.mid(j,80);
                  tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                  if (tmp.size()==0) tmp="0";
                } else {
                  tmp="0";
                }
                qDebug() << "KnightsQuest.zip download =" << tmp;
                ui->KnightsQuestEdit->setText(tmp);
                
                // --- Drupal software ---

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
                j = result.indexOf("oostpoort-v6.x.zip",0);
                t = result.mid(j+20,80);
                tmp = t.mid(t.indexOf("-")+2,3).replace(",",".");
                sum += tmp.toInt(&ok, 10);

                ui->churchEdit1->setText(QString::number(sum));

                 // --- Windows software ---

                j = result.indexOf("PlaatStats.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "PlaatStats.zip download =" << tmp;
                ui->plaatstatsEdit1->setText(tmp);

                j = result.indexOf("PlaatScore.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,4).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "PlaatScore.zip download =" << tmp;
                ui->plaatscoreEdit1->setText(tmp);

                j = result.indexOf("RedSquare-Windows.zip",0);
                t = result.mid(j+20,80);
                tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "RedSquare-Windows.zip download =" << tmp;
                ui->winredsquareEdit1->setText(tmp);

                j = result.indexOf("KnightsQuest-Windows.zip",0);
                t = result.mid(j+20,80);
                tmp = t.mid(t.indexOf("-")+2,4).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "KnightsQuest-Windows.zip download =" << tmp;
                ui->winKnightsQuestEdit1->setText(tmp);

                j = result.indexOf("ChatCostCalc.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,4).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "ChatCostCalc.zip download =" << tmp;
                ui->winChatCostCalcEdit1->setText(tmp);

                j = result.indexOf("WarQuest.zip",0);
                t = result.mid(j,80);
                tmp = t.mid(t.indexOf("-")+2,5).replace(",",".");
                if (tmp.size()==0) tmp="0";
                qDebug() << "WarQuest.zip download =" << tmp;
                ui->winWarQuestClientEdit1->setText(tmp);

                // --- Next request software ---

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

               j = result.indexOf("KnightsQuest",0);
               if (j!=-1) {
                  t = result.mid(j+20,120);
                  k = t.indexOf("<font face='Arial'>");
                  l = t.indexOf("</font>");
                  tmp = t.mid(k+19,(l-(k+19)));
                  if (tmp.size()==0) tmp="0";
               } else {
                  tmp="0";
               }
               qDebug() << "KnightsQuest download =" << tmp;
               ui->KnightsQuestEdit2->setText(formatNumber(tmp));


               address = QString("http://code.google.com/p/pongtwo/downloads/list");
               qDebug() << "Fetch " << address;
               manager->get(QNetworkRequest(address));

               calculate();
               sm++;
             }
             break;

      // Wii Modules

     case 3: {
               // Get Pong2 Google code download
               qDebug() << "Pong2 download";
               ui->pong2Edit3->setText(formatNumber(parseGoogleCodePage(result)));

               address = QString("http://code.google.com/p/biblequiz/downloads/list");
               qDebug() << "Fetch " << address;
               manager->get(QNetworkRequest(address));

               calculate();
               sm++;
             }             
             break;

    case 4: {
              // Get BibleQuiz Google code download
              qDebug() << "BibleQuiz download";
              ui->bibleQuizEdit3->setText(formatNumber(parseGoogleCodePage(result)));

              address = QString("http://code.google.com/p/redsquare/downloads/list");
              qDebug() << "Fetch " << address;
              manager->get(QNetworkRequest(address));

              calculate();
              sm++;
            }
            break;

    case 5: {
              // Get RedSquare Google code download
              qDebug() << "RedSquare download";
              ui->redSquareEdit3->setText(formatNumber(parseGoogleCodePage(result)));

              address = QString("http://code.google.com/p/spacebubble/downloads/list");
              qDebug() << "Fetch " << address;
              manager->get(QNetworkRequest(address));

              calculate();
              sm++;
            }
            break;

    case 6: {
              // Get SpaceBubble Google code download
              qDebug() << "SpaceBubble download";
              ui->spaceBubbleEdit3->setText(formatNumber(parseGoogleCodePage(result)));

              address = QString("http://code.google.com/p/wiitowerdefense/downloads/list");
              qDebug() << "Fetch " << address;
              manager->get(QNetworkRequest(address));

              calculate();
              sm++;
            }
            break;

    case 7: {
              // Get TowerDefense Google code download
              qDebug() << "TowerDefense download";
              ui->towerDefenseEdit3->setText(formatNumber(parseGoogleCodePage(result)));

              address = QString("http://code.google.com/p/wii-knightsquest/downloads/list");
              qDebug() << "Fetch " << address;
              manager->get(QNetworkRequest(address));

              calculate();
              sm++;
            }
            break;

    case 8: {
              // Get KnightsQuest Google code download
              qDebug() << "KnightsQuest download";
              ui->KnightsQuestEdit3->setText(formatNumber(parseGoogleCodePage(result)));

              address = QString("http://code.google.com/p/drupal-addressbook/downloads/list");
              qDebug() << "Fetch " << address;
              manager->get(QNetworkRequest(address));

              calculate();
              sm++;
            }
            break;

   // Drupal Modules

   case 9: {
                // Get Addressbook Google code download
                qDebug() << "Addressbook download";
                ui->addressbookEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                address = QString("http://code.google.com/p/drupal-eventnotification/downloads/list");
                qDebug() << "Fetch " << address;
                manager->get(QNetworkRequest(address));

                calculate();
                sm++;
              }
              break;

    case 10: {
                 // Get EventNofication Google code download
                 qDebug() << "EventNotification download" ;
                 ui->eventNotificationEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                 address = QString("http://code.google.com/p/drupal-oostpoort/downloads/list");
                 qDebug() << "Fetch " << address;
                 manager->get(QNetworkRequest(address));

                 calculate();
                 sm++;
               }
               break;

    case 11: {
                 // Get ChurchAdmin Google code download
                 qDebug() << "ChurchAdmin download ";
                 ui->churchEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                 address = QString("http://code.google.com/p/plaatstats/downloads/list");
                 qDebug() << "Fetch " << address;
                 manager->get(QNetworkRequest(address));

                 calculate();
                 sm++;
               }
               break;


    case 12: {
                 // Get Windows PlaatStats Google code download
                 qDebug() << "PlaatStats download ";
                 ui->plaatstatsEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                 address = QString("http://code.google.com/p/plaatscore/downloads/list");
                 qDebug() << "Fetch " << address;
                 manager->get(QNetworkRequest(address));

                 calculate();
                 sm++;
               }
               break;

    case 13: {
                 // Get Windows PlaatScore Google code download
                 qDebug() << "PlaatScore download ";
                 ui->plaatscoreEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                 address = QString("http://code.google.com/p/windows-redsquare/downloads/list");
                 qDebug() << "Fetch " << address;
                 manager->get(QNetworkRequest(address));

                 calculate();
                 sm++;
               }
               break;

    case 14: {
                 // Get Windows RedSquare Google code download
                 qDebug() << "RedSquare download " ;
                 ui->winredsquareEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                 address = QString("http://code.google.com/p/windows-knightsquest/downloads/list");
                 qDebug() << "Fetch " << address;
                 manager->get(QNetworkRequest(address));

                 calculate();
                 sm++;
               }
               break;

    case 15: {
                 // Get Windows KnightsQuest Google code download
                 qDebug() << "KnightsQuest download ";
                 ui->winKnightsQuestEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                 address = QString("http://code.google.com/p/chatcostcalc/downloads/list");
                 qDebug() << "Fetch " << address;
                 manager->get(QNetworkRequest(address));

                 calculate();
                 sm++;
               }
               break;

    case 16: {
                 // Get Windows ChatCostCalc Google code download
                 qDebug() << "ChatCostCalc download";
                 ui->winChatCostCalcEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                  address = QString("http://code.google.com/p/warquest/downloads/list");
                 qDebug() << "Fetch " << address;
                 manager->get(QNetworkRequest(address));

                 calculate();
                 sm++;
               }
               break;

      case 17: {
                 // Get Windows WarQuest Google code download
                 qDebug() << "WarQuest download";
                 ui->winWarQuestClientEdit2->setText(formatNumber(parseGoogleCodePage(result)));

                 calculate();
                 sm++;

                 ui->actionRefreshData->setEnabled(true);
                 ui->actionCheck_for_update->setEnabled(true);
               }
               break;

        case 20:
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
    calculateWiiApplTotals();
    calculateWiiMyWebsite();
    calculateWiiHomebrewBrowser();
    calculateWiiGoogleCode();
    calculateWiiTotals();

    calculateDrupalMyWebsite();
    calculateDrupalGoogleCode();
    calculateDrupalTotals();

    calculateWindowsMyWebsite();
    calculateWindowsGoogleCode();
    calculateWindowsTotals();
}

/**
 * Calculate Wii Application totals
 */
void MainWindow::calculateWiiApplTotals()
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

   a = convert(ui->KnightsQuestEdit->text());
   b = convert(ui->KnightsQuestEdit2->text());
   c = convert(ui->KnightsQuestEdit3->text());
   ui->KnightsQuestEdit4->setText(formatNumber(a+b+c));
}

/**
 * Calculate Wii My website totals
 */
void MainWindow::calculateWiiMyWebsite()
{
   int a = convert(ui->pong2Edit->text());
   int b = convert(ui->bibleQuizEdit->text());
   int c = convert(ui->redSquareEdit->text());
   int d = convert(ui->spaceBubbleEdit->text());
   int e = convert(ui->towerDefenseEdit->text());
   int f = convert(ui->KnightsQuestEdit->text());
   ui->totals->setText(formatNumber(a+b+c+d+e+f));
}

/**
 * Calculate CodeMii totals
 */
void MainWindow::calculateWiiHomebrewBrowser()
{
   int a = convert(ui->pong2Edit2->text());
   int b = convert(ui->bibleQuizEdit2->text());
   int c = convert(ui->redSquareEdit2->text());
   int d = convert(ui->spaceBubbleEdit2->text());
   int e = convert(ui->towerDefenseEdit2->text());
   int f = convert(ui->KnightsQuestEdit2->text());
   ui->totals2->setText(formatNumber(a+b+c+d+e+f));
}

/**
 * Calculate Google Code totals
 */
void MainWindow::calculateWiiGoogleCode()
{
   int a = convert(ui->pong2Edit3->text());
   int b = convert(ui->bibleQuizEdit3->text());
   int c = convert(ui->redSquareEdit3->text());
   int d = convert(ui->spaceBubbleEdit3->text());
   int e = convert(ui->towerDefenseEdit3->text());
   int f = convert(ui->KnightsQuestEdit3->text());
   ui->totals3->setText(formatNumber(a+b+c+d+e+f));
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
   int f = convert(ui->KnightsQuestEdit4->text());
   ui->totals4->setText(formatNumber(a+b+c+d+e+f));
}

/**
 * Calculate Drupals My Website total
 */
void MainWindow::calculateDrupalMyWebsite()
{
   int a = convert(ui->addressbookEdit1->text());
   int b = convert(ui->eventNotificationEdit1->text());
   int c = convert(ui->churchEdit1->text());
   ui->totalsDrupalEdit1->setText(formatNumber(a+b+c));
}

/**
 * Calculate Drupals Google Code total
 */
void MainWindow::calculateDrupalGoogleCode()
{
   int a = convert(ui->addressbookEdit2->text());
   int b = convert(ui->eventNotificationEdit2->text());
   int c = convert(ui->churchEdit2->text());
   ui->totalsDrupalEdit2->setText(formatNumber(a+b+c));
}

/**
 * Calculate Drupals Totals
 */
void MainWindow::calculateDrupalTotals()
{
   int a = convert(ui->addressbookEdit1->text());
   int b = convert(ui->addressbookEdit2->text());
   ui->addressbookEdit3->setText(formatNumber(a+b));

   a = convert(ui->eventNotificationEdit1->text());
   b = convert(ui->eventNotificationEdit2->text());
   ui->eventNotificationEdit3->setText(formatNumber(a+b));

   a = convert(ui->churchEdit1->text());
   b = convert(ui->churchEdit2->text());
   ui->churchEdit3->setText(formatNumber(a+b));

   a = convert(ui->totalsDrupalEdit1->text());
   b = convert(ui->totalsDrupalEdit2->text());
   ui->totalsDrupalEdit3->setText(formatNumber(a+b));
}

/**
 * Calculate Windows My Website total
 */
void MainWindow::calculateWindowsMyWebsite()
{
   int a = convert(ui->plaatstatsEdit1->text());
   int b = convert(ui->plaatscoreEdit1->text());
   int c = convert(ui->winredsquareEdit1->text());
   int d = convert(ui->winKnightsQuestEdit1->text());
   int e = convert(ui->winChatCostCalcEdit1->text());
   int f = convert(ui->winWarQuestClientEdit1->text());
   ui->totalsWindowsEdit1->setText(formatNumber(a+b+c+d+e+f));
}

/**
 * Calculate Windows Google Code total
 */
void MainWindow::calculateWindowsGoogleCode()
{
   int a = convert(ui->plaatstatsEdit2->text());
   int b = convert(ui->plaatscoreEdit2->text());
   int c = convert(ui->winredsquareEdit2->text());
   int d = convert(ui->winKnightsQuestEdit2->text());
   int e = convert(ui->winChatCostCalcEdit2->text());
   int f = convert(ui->winWarQuestClientEdit2->text());
   ui->totalsWindowsEdit2->setText(formatNumber(a+b+c+d+e+f));
}

/**
 * Calculate Windows Totals
 */
void MainWindow::calculateWindowsTotals()
{
   int a = convert(ui->plaatstatsEdit1->text());
   int b = convert(ui->plaatstatsEdit2->text());
   ui->plaatstatsEdit3->setText(formatNumber(a+b));

   a = convert(ui->plaatscoreEdit1->text());
   b = convert(ui->plaatscoreEdit2->text());
   ui->plaatscoreEdit3->setText(formatNumber(a+b));

   a = convert(ui->winredsquareEdit1->text());
   b = convert(ui->winredsquareEdit2->text());
   ui->winredsquareEdit3->setText(formatNumber(a+b));

   a = convert(ui->winKnightsQuestEdit1->text());
   b = convert(ui->winKnightsQuestEdit2->text());
   ui->winKnightsQuestEdit3->setText(formatNumber(a+b));

   a = convert(ui->winChatCostCalcEdit1->text());
   b = convert(ui->winChatCostCalcEdit2->text());
   ui->winChatCostCalcEdit3->setText(formatNumber(a+b));

   a = convert(ui->winWarQuestClientEdit1->text());
   b = convert(ui->winWarQuestClientEdit2->text());
   ui->winWarQuestClientEdit3->setText(formatNumber(a+b));

   a = convert(ui->totalsWindowsEdit1->text());
   b = convert(ui->totalsWindowsEdit2->text());
   ui->totalsWindowsEdit3->setText(formatNumber(a+b));
}

/**
 * Process request HTTP response.
 */
void MainWindow::replyFinished(QNetworkReply *reply)
{
    QString sA = QString::number( reply->bytesAvailable());
    result = reply->readAll();

    qDebug() << "Request " << sm << "Bytes received " << sA;

    qDebug() << result;

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

void MainWindow::on_actionDonate_triggered()
{
    // Set settings window position related to Main window.
    QPoint position = QPoint(pos());
    position.setX(position.x()+50);
    position.setY(position.y()+120);
    donate.move(position);

    // Disable Man window
    setDisabled(true);

    // Make settings window visible
    donate.show();
}

// ---------------------------------------------------
// The End
// ---------------------------------------------------



