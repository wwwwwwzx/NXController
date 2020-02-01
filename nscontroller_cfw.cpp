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

void nscontroller_cfw::send(QString msg) {
  ts.write((msg + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::click(QString button) {
  send("click " + button);
}

void nscontroller_cfw::press(QString button) {
  send("press " + button);
}

void nscontroller_cfw::release(QString button) {
  send("release " + button);
}

QString nscontroller_cfw::tohex(short n) {
  return QString(n < 0 ? "-" : "") + "0x" + QString::number(abs(n), 16);
}

void nscontroller_cfw::LStick(short x, short y) {
  LS_X = x;
  LS_Y = y;
  send("setStick LEFT " + tohex(x) + " " + tohex(y));
}

void nscontroller_cfw::RStick(short x, short y) {
  RS_X = x;
  RS_Y = y;
  send("setStick RIGHT " + tohex(x) + " " + tohex(y));
}

QString nscontroller_cfw::peek(uint offset, uint size) {
  send("peek 0x" + QString::number(offset, 16) + " " + QString::number(size));
  ts.waitForReadyRead();
  return "0x" + ts.readAll();
}

QString nscontroller_cfw::peek(QString offset, QString size) {
  send("peek 0x" + offset + " " + size);
  ts.waitForReadyRead();
  return "0x" + ts.readAll();
}

void nscontroller_cfw::poke(uint offset, QByteArray data) {
  send("poke 0x" + QString::number(offset, 16) + " 0x" + data.toHex(0));
}

void nscontroller_cfw::poke(QString offset, QString data) {
  send("poke 0x" + offset + " " + data);
}

void nscontroller_cfw::close() {
  ts.close();
}
