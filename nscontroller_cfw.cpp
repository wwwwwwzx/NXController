/*
 * This file is part of NSController
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

#include "nscontroller_cfw.h"
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>

nscontroller_cfw::nscontroller_cfw() {}

bool nscontroller_cfw::connect(QString IP) {
  ts.connectToHost(QHostAddress(IP), 6000);
  return ts.open(QIODevice::ReadWrite);
}

void nscontroller_cfw::click(QString button) {
  ts.write(("click " + button + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::press(QString button) {
  ts.write(("press " + button + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::release(QString button) {
  ts.write(("release " + button + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::LStick(short x, short y) {
  LS_X = x;
  LS_Y = y;
  QString xsign = x < 0 ? "-" : "";
  QString ysign = y < 0 ? "-" : "";
  QString output = "setStick LEFT " + xsign + "0x" + QString::number(abs(x), 16) + " " + ysign + "0x" + QString::number(abs(y), 16) + "\r\n";
  ts.write(output.toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::RStick(short x, short y) {
  RS_X = x;
  RS_Y = y;
  QString xsign = x < 0 ? "-" : "";
  QString ysign = y < 0 ? "-" : "";
  QString output = "setStick RIGHT " + xsign + "0x" + QString::number(abs(x), 16) + " " + ysign + "0x" + QString::number(abs(y), 16) + "\r\n";
  ts.write(output.toUtf8());
  ts.waitForBytesWritten();
}

QString nscontroller_cfw::peek(uint offset, uint size) {
  QString output = "peek 0x" + QString::number(offset, 16) + " " + QString::number(size) + "\r\n";
  ts.write(output.toUtf8());
  ts.waitForBytesWritten();
  ts.waitForReadyRead();
  return "0x" + ts.readAll();
}

QString nscontroller_cfw::peek(QString offset, QString size) {
  QString output = "peek 0x" + offset + " " + size + "\r\n";
  ts.write(output.toUtf8());
  ts.waitForBytesWritten();
  ts.waitForReadyRead();
  return "0x" + ts.readAll();
}

void nscontroller_cfw::poke(uint offset, QByteArray data) {
  ts.write(("poke 0x" + QString::number(offset, 16) + " 0x" + data.toHex(0) + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::poke(QString offset, QString data) {
  ts.write(("poke 0x" + offset + " " + data + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::close() {
  ts.close();
}
