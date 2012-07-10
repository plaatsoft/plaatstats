/**
 *  @file
 *  @brief The file contain the about window
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

#ifndef ABOUT_H
#define ABOUT_H

#include <QtGui>

namespace Ui {
    class About;
}

class About : public QWidget {
    Q_OBJECT
public:
    About(QWidget *parent = 0);
    ~About();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::About *ui;
    QGraphicsScene *scene;
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_pressed();
};

#endif // ABOUT_H

// ********************************************
// The end
// ********************************************
