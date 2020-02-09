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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buttonconfig.h"
#include <QSettings>
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QKeyEvent>
#include <QThread>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  qRegisterMetaTypeStreamOperators<inputtable>("inputtable");
  QSettings setting;
  on_B_Refresh_clicked();
  showhidebuttons();
  ui->L_MousePad->setStyleSheet("QLabel {color: white; background-color: black}");
  setMinimumHeight(135);
  setMaximumHeight(135);
  ui->ipaddress->setText(setting.value("settings/ip", "192.168.0.1").toString());
  ui->ramaddress->setText(setting.value("settings/ramaddress", "0").toString());
  ui->datasize->setText(setting.value("settings/datasize", "8").toString());
  loadbuttonconfig();
  on_B_Connect_clicked();
  if (isDisconnected)
    ui->RB_Socket->setChecked(true);
  if (ui->ipaddress->text() != "192.168.0.1")
    on_B_Connect_clicked();  // Try to connect sys-botbase
}

MainWindow::~MainWindow() {
  delete ui;
}
void MainWindow::on_B_Refresh_clicked() {
  QSettings setting;
  QString last_device = setting.value("settings/serialport", "").toString();
  ui->devicelist->clear();
  Q_FOREACH (QSerialPortInfo port, QSerialPortInfo::availablePorts())
    if (port.hasProductIdentifier()) {
      ui->devicelist->addItem((port.portName()));
      if (port.portName() == last_device)
        ui->devicelist->setCurrentIndex(ui->devicelist->count() - 1);
    }
}

void MainWindow::showhidebuttons() {
  ui->B_Connect->setVisible(isDisconnected);
  ui->B_Disconnect->setVisible(!isDisconnected);
  ui->devicelist->setEnabled(isDisconnected);
  ui->ipaddress->setEnabled(isDisconnected);
  ui->RB_Serial->setEnabled(isDisconnected);
  ui->RB_Socket->setEnabled(isDisconnected);
  ui->B_Refresh->setEnabled(isDisconnected);
  ui->B_UseMouse->setVisible(!isDisconnected && ui->RB_Socket->isChecked());
  if (isDisconnected)
    ui->L_MousePad->setVisible(false);
}

void MainWindow::on_B_Connect_clicked() {
  QSettings setting;
  if (ui->RB_Serial->isChecked()) {
    if (!c.connect(ui->devicelist->currentText()))
      return;
    setting.setValue("settings/serialport", ui->devicelist->currentText());
  } else {
    QStringList buffer = ui->ipaddress->text().split(":");
    short port = 6000;
    if (buffer.length() > 1)
      port = buffer[1].toShort();
    if (!b.connect(buffer[0],port)) {
      QMessageBox MB;
      MB.critical(0, "Error", "Connection failed");
      MB.setFixedSize(500, 180);
      return;
    }
    b.configuresleep(0, 50);  // Default setting
    setMaximumHeight(210);
    setMinimumHeight(210);
    setting.setValue("settings/ip", ui->ipaddress->text());
  }
  isDisconnected = false;
  showhidebuttons();
}

void MainWindow::on_B_Disconnect_clicked() {
  if (ui->RB_Serial->isChecked())
    c.close();
  else {
    b.detachController();
    b.close();
  }
  setMinimumHeight(135);
  setMaximumHeight(135);
  resize(380, 135);
  isDisconnected = true;
  showhidebuttons();
}

void MainWindow::on_B_Read_clicked() {
  if (isDisconnected || ui->RB_Serial->isChecked())
    return;
  QSettings setting;
  QString datastring = b.peek(ui->ramaddress->text(), ui->datasize->text());
  ui->data->setText(datastring);
  setting.setValue("settings/ramaddress", ui->ramaddress->text());
  setting.setValue("settings/datasize", ui->datasize->text());
  if (QGuiApplication::keyboardModifiers() == Qt::ShiftModifier) {
    int size = (datastring.count() - 2) / 2;
    QByteArray ay(size, 0);
    for (int i = 0; i < size; i++)
      ay[i] = datastring.mid(i * 2 + 2, 2).toInt(nullptr, 16);
    QFile file("dump_heap_0x" + ui->ramaddress->text() + "_" + ui->datasize->text() + ".bin");
    file.open(QIODevice::WriteOnly);
    file.write(ay);
    file.close();
  }
}

void MainWindow::on_B_Write_clicked() {
  if (isDisconnected || ui->RB_Serial->isChecked())
    return;
  QSettings setting;
  b.poke(ui->ramaddress->text(), ui->data->text());
  setting.setValue("settings/ramaddress", ui->ramaddress->text());
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
  if (isUsingMouse && event->key() == Qt::Key_F9) {
    releaseMouse();
    isUsingMouse = false;
    ui->L_MousePad->setVisible(false);
    setCursor(Qt::ArrowCursor);
  }
  if (isDisconnected)
    return;
  if (event->isAutoRepeat())
    return;
  int key = event->key();
  if (ui->RB_Serial->isChecked()) {
    if (key == keytable.A)
      c.A(-1);
    else if (key == keytable.B)
      c.B(-1);
    else if (key == keytable.X)
      c.X(-1);
    else if (key == keytable.Y)
      c.Y(-1);
    else if (key == keytable.LS_Up)
      c.LS_Up(-1);
    else if (key == keytable.LS_Down)
      c.LS_Down(-1);
    else if (key == keytable.LS_Left)
      c.LS_Left(-1);
    else if (key == keytable.LS_Right)
      c.LS_Right(-1);
    else if (key == keytable.RS_Up)
      c.RS_Up(-1);
    else if (key == keytable.RS_Down)
      c.RS_Down(-1);
    else if (key == keytable.RS_Left)
      c.RS_Left(-1);
    else if (key == keytable.RS_Right)
      c.RS_Right(-1);
    else if (key == keytable.D_Up)
      c.Up(-1);
    else if (key == keytable.D_Down)
      c.Down(-1);
    else if (key == keytable.D_Left)
      c.Left(-1);
    else if (key == keytable.D_Right)
      c.Right(-1);
    else if (key == keytable.Home)
      c.Home();
    else if (key == keytable.Capture)
      c.Capture(-1);
    else if (key == keytable.Plus)
      c.Plus(-1);
    else if (key == keytable.Minus)
      c.Minus(-1);
    else if (key == keytable.L)
      c.L(-1);
    else if (key == keytable.R)
      c.R(-1);
    else if (key == keytable.ZL)
      c.ZL(-1);
    else if (key == keytable.ZR)
      c.ZR(-1);
    else if (key == keytable.LS)
      c.PressLeftStick(-1);
    else if (key == keytable.RS)
      c.PressRightStick(-1);
  } else {
    if (key == keytable.A)
      b.press("A");
    else if (key == keytable.B)
      b.press("B");
    else if (key == keytable.X)
      b.press("X");
    else if (key == keytable.Y)
      b.press("Y");
    else if (key == keytable.D_Up)
      b.press("DUP");
    else if (key == keytable.D_Down)
      b.press("DDOWN");
    else if (key == keytable.D_Left)
      b.press("DLEFT");
    else if (key == keytable.D_Right)
      b.press("DRIGHT");
    else if (key == keytable.Home)
      b.press("HOME");
    else if (key == keytable.Capture)
      b.press("CAPTURE");
    else if (key == keytable.Plus)
      b.press("PLUS");
    else if (key == keytable.Minus)
      b.press("MINUS");
    else if (key == keytable.L)
      b.press("L");
    else if (key == keytable.R)
      b.press("R");
    else if (key == keytable.ZL)
      b.press("ZL");
    else if (key == keytable.ZR)
      b.press("ZR");
    else if (key == keytable.LS)
      b.press("LSTICK");
    else if (key == keytable.RS)
      b.press("RSTICK");
    else if (key == keytable.LS_Up)
      b.LStick(b.LS_X, 0x7FFF);
    else if (key == keytable.LS_Down)
      b.LStick(b.LS_X, -0x8000);
    else if (key == keytable.LS_Left)
      b.LStick(-0x8000, b.LS_Y);
    else if (key == keytable.LS_Right)
      b.LStick(0x7FFF, b.LS_Y);
    else if (key == keytable.RS_Up)
      b.RStick(b.RS_X, 0x7FFF);
    else if (key == keytable.RS_Down)
      b.RStick(b.RS_X, -0x8000);
    else if (key == keytable.RS_Left)
      b.RStick(-0x8000, b.RS_Y);
    else if (key == keytable.RS_Right)
      b.RStick(0x7FFF, b.RS_Y);
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
  if (isDisconnected)
    return;
  if (event->isAutoRepeat())
    return;
  int key = event->key();
  if (ui->RB_Serial->isChecked()) {
    if (key == keytable.A)
      c.A(-1);
    else if (key == keytable.B)
      c.B(-1);
    else if (key == keytable.X)
      c.X(-1);
    else if (key == keytable.Y)
      c.Y(-1);
    else if (key == keytable.LS_Left || key == keytable.LS_Right)
      c.LS_XCenter();
    else if (key == keytable.LS_Up || key == keytable.LS_Down)
      c.LS_YCenter();
    else if (key == keytable.RS_Left || key == keytable.RS_Right)
      c.RS_XCenter();
    else if (key == keytable.RS_Up || key == keytable.RS_Down)
      c.RS_YCenter();
    else if (key == keytable.D_Up || key == keytable.D_Down || key == keytable.D_Left || key == keytable.D_Right)
      c.Dpad_Center();
    else if (key == keytable.Capture)
      c.Capture(-1);
    else if (key == keytable.Plus)
      c.Plus(-1);
    else if (key == keytable.Minus)
      c.Minus(-1);
    else if (key == keytable.L)
      c.L(-1);
    else if (key == keytable.R)
      c.R(-1);
    else if (key == keytable.ZL)
      c.ZL(-1);
    else if (key == keytable.ZR)
      c.ZR(-1);
    else if (key == keytable.LS)
      c.PressLeftStick(-1);
    else if (key == keytable.RS)
      c.PressRightStick(-1);
  } else {
    if (key == keytable.A)
      b.release("A");
    else if (key == keytable.B)
      b.release("B");
    else if (key == keytable.X)
      b.release("X");
    else if (key == keytable.Y)
      b.release("Y");
    else if (key == keytable.Home)
      b.release("HOME");
    else if (key == keytable.Capture)
      b.release("CAPTURE");
    else if (key == keytable.Plus)
      b.release("PLUS");
    else if (key == keytable.Minus)
      b.release("MINUS");
    else if (key == keytable.D_Up)
      b.release("DUP");
    else if (key == keytable.D_Down)
      b.release("DDOWN");
    else if (key == keytable.D_Left)
      b.release("DLEFT");
    else if (key == keytable.D_Right)
      b.release("DRIGHT");
    else if (key == keytable.L)
      b.release("L");
    else if (key == keytable.R)
      b.release("R");
    else if (key == keytable.ZL)
      b.release("ZL");
    else if (key == keytable.ZR)
      b.release("ZR");
    else if (key == keytable.LS)
      b.release("LSTICK");
    else if (key == keytable.RS)
      b.release("RSTICK");
    else if (key == keytable.LS_Left || key == keytable.LS_Right)
      b.LStick(0, b.LS_Y);
    else if (key == keytable.LS_Up || key == keytable.LS_Down)
      b.LStick(b.LS_X, 0);
    else if (key == keytable.RS_Left || key == keytable.RS_Right)
      b.RStick(0, b.RS_Y);
    else if (key == keytable.RS_Up || key == keytable.RS_Down)
      b.RStick(b.RS_X, 0);
  }
}

void MainWindow::on_B_Settings_clicked() {
  auto* setting = new buttonconfig();
  setting->show();
  loadbuttonconfig();
}

void MainWindow::loadbuttonconfig() {
  QSettings setting;
  auto table = setting.value("settings/keyconfig", qVariantFromValue(keytable));
  if (table.isValid())
    keytable = table.value<inputtable>();
}

void MainWindow::on_B_UseMouse_clicked() {
  if (!isUsingMouse) {
    isUsingMouse = true;
    setMouseTracking(true);
    grabMouse();
    ui->L_MousePad->setVisible(true);
    setCursor(Qt::BlankCursor);
  }
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
  if (isDisconnected || !isUsingMouse)
    return;
  QKeyEvent ke = QKeyEvent(QEvent::KeyPress, Qt::NoButton, Qt::NoModifier);
  if (event->button() == Qt::LeftButton)
    ke = QKeyEvent(QEvent::KeyPress, keytable.Mouse_Left, Qt::NoModifier);
  else if (event->button() == Qt::RightButton)
    ke = QKeyEvent(QEvent::KeyPress, keytable.Mouse_Right, Qt::NoModifier);
  else if (event->button() == Qt::MidButton)
    ke = QKeyEvent(QEvent::KeyPress, keytable.Mouse_Middle, Qt::NoModifier);
  else
    return;
  keyPressEvent(&ke);
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {
  if (isDisconnected || !isUsingMouse)
    return;
  QKeyEvent ke = QKeyEvent(QEvent::KeyRelease, Qt::NoButton, Qt::NoModifier);
  if (event->button() == Qt::LeftButton)
    ke = QKeyEvent(QEvent::KeyRelease, keytable.Mouse_Left, Qt::NoModifier);
  else if (event->button() == Qt::RightButton)
    ke = QKeyEvent(QEvent::KeyRelease, keytable.Mouse_Right, Qt::NoModifier);
  else if (event->button() == Qt::MidButton)
    ke = QKeyEvent(QEvent::KeyRelease, keytable.Mouse_Middle, Qt::NoModifier);
  else
    return;
  keyReleaseEvent(&ke);
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
  if (isDisconnected || !isUsingMouse)
    return;
  int dx = 0, dy = 0;
  for (int i = 0; i < 10; i++) {
    dx += (event->x() - width() / 2) * 0x800;
    dy += (event->y() - height() / 2) * 0x800;
    QCursor::setPos(mapToGlobal(QPoint(width() / 2, height() / 2)));
    QThread::msleep(10);
  }
  b.RStick(dx, -dy);
}
