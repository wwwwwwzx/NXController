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

#ifndef NSCONTROLLER_H
#define NSCONTROLLER_H
#include <QString>
#include <QSerialPort>

class nscontroller {
 public:
  nscontroller();
  bool connect(QString port);
  void release();
  void close();

  void A(int duration = 100);
  void B(int duration = 100);
  void X(int duration = 100);
  void Y(int duration = 100);
  void L(int duration = 100);
  void R(int duration = 100);
  void ZL(int duration = 100);
  void ZR(int duration = 100);
  void Plus(int duration = 100);
  void Minus(int duration = 100);
  void Home(int duration = 100);
  void Capture(int duration = 100);

  // Dpad
  void Up(int duration = 100);
  void Down(int duration = 100);
  void Left(int duration = 100);
  void Right(int duration = 100);
  void Dpad_Center();

  // Left Stick
  void LS_Left(int duration = 100);
  void LS_Right(int duration = 100);
  void LS_Up(int duration = 100);
  void LS_Down(int duration = 100);
  void LS_XCenter();
  void LS_YCenter();
  void PressLeftStick(int duration = 100);

  // Right Stick
  void RS_Left(int duration = 100);
  void RS_Right(int duration = 100);
  void RS_Up(int duration = 100);
  void RS_Down(int duration = 100);
  void RS_XCenter();
  void RS_YCenter();
  void PressRightStick(int duration = 100);

 private:
  QSerialPort ser;
  int buttondelay = 100;
  void write(QString msg);
  void send(QString msg, int duration = 100);
};

#endif  // NSCONTROLLER_H
