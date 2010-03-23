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
