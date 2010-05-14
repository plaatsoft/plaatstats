/**
 *  @file
 *  @brief The file contain the donate window
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

#ifndef DONATE_H
#define DONATE_H

#include <QWidget>

namespace Ui {
    class Donate;
}

class Donate : public QWidget {Q_OBJECT

public:
    Donate(QWidget *parent = 0);
    ~Donate();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Donate *ui;

    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();
};

#endif // DONATE_H

// ********************************************
// The end
// ********************************************
