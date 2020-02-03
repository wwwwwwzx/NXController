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
  void on_buttonBox_accepted();

  void on_K_A_textChanged(const QString& arg1);
  void on_K_B_textChanged(const QString& arg1);
  void on_K_X_textChanged(const QString& arg1);
  void on_K_Y_textChanged(const QString& arg1);

 private:
  Ui::buttonconfig* ui;
  inputtable config;
};

#endif  // BUTTONCONFIG_H
