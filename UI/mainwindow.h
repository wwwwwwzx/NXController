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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nxcontroller.h"
#include "nxcontroller_cfw.h"
#include "inputtable.h"

QT_BEGIN_NAMESPACE
namespace Ui {
  class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  void keyPressEvent(QKeyEvent* event);
  void keyReleaseEvent(QKeyEvent* event);
  nxcontroller c;
  nxcontroller_cfw b;
  inputtable keytable;
  void mouseMoveEvent(QMouseEvent* event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);

 private slots:
  void on_B_Refresh_clicked();
  void on_B_Connect_clicked();
  void on_B_Disconnect_clicked();
  void on_B_Write_clicked();
  void on_B_Read_clicked();
  void on_B_Settings_clicked();
  void on_B_UseMouse_clicked();

 private:
  void loadbuttonconfig();
  Ui::MainWindow* ui;
  bool isUsingMouse, isDisconnected = true;
  void showhidebuttons();
  int Prev_X, Prev_Y;
};
#endif  // MAINWINDOW_H
