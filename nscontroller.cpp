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

#include "nscontroller.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QThread>

nscontroller::nscontroller() {}

bool nscontroller::connect(QString port) {
  if (port == "")
    return false;
  ser.setPortName(port);
  return ser.open(QIODevice::WriteOnly);
}

void nscontroller::write(QString msg) {
  ser.write((msg + "\r\n").toUtf8());
  ser.waitForBytesWritten();
}

void nscontroller::release() {
  ser.write("RELEASE\r\n");
  ser.waitForBytesWritten();
}

void nscontroller::send(QString msg, int duration) {
  write(msg);
  if (duration > 0) {
    QThread::msleep(duration);
    release();
    QThread::msleep(buttondelay);
  }
}

void nscontroller::close() {
  release();
  QThread::msleep(500);
  ser.close();
}

void nscontroller::A(int duration) {
  send("Button A", duration);
}
void nscontroller::B(int duration) {
  send("Button B", duration);
}
void nscontroller::X(int duration) {
  send("Button X", duration);
}
void nscontroller::Y(int duration) {
  send("Button Y", duration);
}
void nscontroller::L(int duration) {
  send("Button L", duration);
}
void nscontroller::R(int duration) {
  send("Button R", duration);
}
void nscontroller::ZL(int duration) {
  send("Button ZL", duration);
}
void nscontroller::ZR(int duration) {
  send("Button ZR", duration);
}
void nscontroller::Plus(int duration) {
  send("Button PLUS", duration);
}
void nscontroller::Minus(int duration) {
  send("Button MINUS", duration);
}
void nscontroller::Home(int duration) {
  send("Button HOME", duration);
}
void nscontroller::Capture(int duration) {
  send("Button CAPTURE", duration);
}

// Dpad
void nscontroller::Up(int duration) {
  send("HAT TOP", duration);
}
void nscontroller::Down(int duration) {
  send("HAT BOTTOM", duration);
}
void nscontroller::Left(int duration) {
  send("HAT LEFT", duration);
}
void nscontroller::Right(int duration) {
  send("HAT RIGHT", duration);
}
void nscontroller::Dpad_Center() {
  send("HAT CENTER", -1);
}

// Left stick
void nscontroller::LS_Left(int duration) {
  send("LX MIN", duration);
}
void nscontroller::LS_Right(int duration) {
  send("LX MAX", duration);
}
void nscontroller::LS_Up(int duration) {
  send("LY MIN", duration);
}
void nscontroller::LS_Down(int duration) {
  send("LY MAX", duration);
}
void nscontroller::LS_XCenter() {
  send("LX CENTER", -1);
}
void nscontroller::LS_YCenter() {
  send("LY CENTER", -1);
}
void nscontroller::PressLeftStick(int duration) {
  send("Button LCLICK", duration);
}

// Right stick
void nscontroller::RS_Left(int duration) {
  send("RX MIN", duration);
}
void nscontroller::RS_Right(int duration) {
  send("RX MAX", duration);
}
void nscontroller::RS_Up(int duration) {
  send("RY MIN", duration);
}
void nscontroller::RS_Down(int duration) {
  send("RY MAX", duration);
}
void nscontroller::RS_XCenter() {
  send("RX CENTER", -1);
}
void nscontroller::RS_YCenter() {
  send("RY CENTER", -1);
}
void nscontroller::PressRightStick(int duration) {
  send("Button RCLICK", duration);
}
