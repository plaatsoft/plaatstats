/**
 *  @file
 *  @brief The file contain the statistics windows
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

#ifndef STATS_H
#define STATS_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void about();
    void fetch();
    void replyFinished(QNetworkReply*);
    void fillClipboard();

protected:
    void changeEvent(QEvent *e);

private:
    void createActions();
    void stateMachine();
    const char *getDate();
    int convert(QString number);
    QString formatNumber(int number);
    QString formatNumber(QString number);

    void calculate();
    void calculateApplTotals();
    void calculateWebsite();
    void calculateHomebrewBrowser();
    void calculateGoogleCode();
    void calculateWiiTotals();
    void calculateDrupalTotals();

    void closeEvent(QCloseEvent *event);
    void readSettings();
    void writeSettings();

    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QString result;
    int sm;

    QAction *fetchAct;
};

#endif // STATS_H
