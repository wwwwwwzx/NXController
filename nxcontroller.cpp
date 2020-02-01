/*
 * This file is part of nxcontroller
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

#include "nxcontroller.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QThread>

nxcontroller::nxcontroller() {}

bool nxcontroller::connect(QString port) {
  if (port == "")
    return false;
  ser.setPortName(port);
  return ser.open(QIODevice::WriteOnly);
}

void nxcontroller::write(QString msg) {
  ser.write((msg + "\r\n").toUtf8());
  ser.waitForBytesWritten();
}

void nxcontroller::release() {
  ser.write("RELEASE\r\n");
  ser.waitForBytesWritten();
}

void nxcontroller::send(QString msg, int duration) {
  write(msg);
  if (duration > 0) {
    QThread::msleep(duration);
    release();
    QThread::msleep(buttondelay);
  }
}

void nxcontroller::close() {
  release();
  QThread::msleep(500);
  ser.close();
}

void nxcontroller::A(int duration) {
  send("Button A", duration);
}
void nxcontroller::B(int duration) {
  send("Button B", duration);
}
void nxcontroller::X(int duration) {
  send("Button X", duration);
}
void nxcontroller::Y(int duration) {
  send("Button Y", duration);
}
void nxcontroller::L(int duration) {
  send("Button L", duration);
}
void nxcontroller::R(int duration) {
  send("Button R", duration);
}
void nxcontroller::ZL(int duration) {
  send("Button ZL", duration);
}
void nxcontroller::ZR(int duration) {
  send("Button ZR", duration);
}
void nxcontroller::Plus(int duration) {
  send("Button PLUS", duration);
}
void nxcontroller::Minus(int duration) {
  send("Button MINUS", duration);
}
void nxcontroller::Home(int duration) {
  send("Button HOME", duration);
}
void nxcontroller::Capture(int duration) {
  send("Button CAPTURE", duration);
}

// Dpad
void nxcontroller::Up(int duration) {
  send("HAT TOP", duration);
}
void nxcontroller::Down(int duration) {
  send("HAT BOTTOM", duration);
}
void nxcontroller::Left(int duration) {
  send("HAT LEFT", duration);
}
void nxcontroller::Right(int duration) {
  send("HAT RIGHT", duration);
}
void nxcontroller::Dpad_Center() {
  send("HAT CENTER", -1);
}

// Left stick
void nxcontroller::LS_Left(int duration) {
  send("LX MIN", duration);
}
void nxcontroller::LS_Right(int duration) {
  send("LX MAX", duration);
}
void nxcontroller::LS_Up(int duration) {
  send("LY MIN", duration);
}
void nxcontroller::LS_Down(int duration) {
  send("LY MAX", duration);
}
void nxcontroller::LS_XCenter() {
  send("LX CENTER", -1);
}
void nxcontroller::LS_YCenter() {
  send("LY CENTER", -1);
}
void nxcontroller::PressLeftStick(int duration) {
  send("Button LCLICK", duration);
}

// Right stick
void nxcontroller::RS_Left(int duration) {
  send("RX MIN", duration);
}
void nxcontroller::RS_Right(int duration) {
  send("RX MAX", duration);
}
void nxcontroller::RS_Up(int duration) {
  send("RY MIN", duration);
}
void nxcontroller::RS_Down(int duration) {
  send("RY MAX", duration);
}
void nxcontroller::RS_XCenter() {
  send("RX CENTER", -1);
}
void nxcontroller::RS_YCenter() {
  send("RY CENTER", -1);
}
void nxcontroller::PressRightStick(int duration) {
  send("Button RCLICK", duration);
}
