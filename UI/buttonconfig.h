/*
 * This file is part of NXController
 * Copyright (C) 2020 by wwwwwwzx
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef BUTTONCONFIG_H
#define BUTTONCONFIG_H

#include <QDialog>
#include "inputtable.h"

namespace Ui {
  class buttonconfig;
}

class buttonconfig : public QDialog {
  Q_OBJECT

 public:
  explicit buttonconfig(QWidget* parent = nullptr);
  ~buttonconfig();

 private slots:
  void loadsettings();

  void on_B_Default_clicked();
  void on_buttonBox_accepted();

  void on_K_A_textChanged(const QString& newtext);
  void on_K_B_textChanged(const QString& newtext);
  void on_K_X_textChanged(const QString& newtext);
  void on_K_Y_textChanged(const QString& newtext);
  void on_K_L_textChanged(const QString& newtext);
  void on_K_R_textChanged(const QString& newtext);
  void on_K_ZL_textChanged(const QString& newtext);
  void on_K_ZR_textChanged(const QString& newtext);
  void on_K_LS_textChanged(const QString& newtext);
  void on_K_RS_textChanged(const QString& newtext);
  void on_K_Home_textChanged(const QString& newtext);
  void on_K_Capture_textChanged(const QString& newtext);
  void on_K_Plus_textChanged(const QString& newtext);
  void on_K_Minus_textChanged(const QString& newtext);

  void on_K_D_Left_textChanged(const QString& newtext);
  void on_K_D_Right_textChanged(const QString& newtext);
  void on_K_D_Up_textChanged(const QString& newtext);
  void on_K_D_Down_textChanged(const QString& newtext);
  void on_K_LS_Left_textChanged(const QString& newtext);
  void on_K_LS_Right_textChanged(const QString& newtext);
  void on_K_LS_Up_textChanged(const QString& newtext);
  void on_K_LS_Down_textChanged(const QString& newtext);
  void on_K_RS_Left_textChanged(const QString& newtext);
  void on_K_RS_Right_textChanged(const QString& newtext);
  void on_K_RS_Up_textChanged(const QString& newtext);
  void on_K_RS_Down_textChanged(const QString& newtext);

  void on_K_Mouse_Left_textChanged(const QString& newtext);
  void on_K_Mouse_Right_textChanged(const QString& newtext);
  void on_K_Mouse_Middle_textChanged(const QString& newtext);

 private:
  Ui::buttonconfig* ui;
  inputtable config;
};

#endif  // BUTTONCONFIG_H
