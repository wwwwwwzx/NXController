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

#ifndef NSCONTROLLER_CFW_H
#define NSCONTROLLER_CFW_H
#include <QTcpSocket>
#include <QString>

class nscontroller_cfw {
 public:
  nscontroller_cfw();
  bool connect(QString IP);
  void press(QString button);
  void click(QString button);
  void release(QString button);
  void LStick(short x, short y);
  void RStick(short x, short y);
  short LS_X = 0, LS_Y = 0, RS_X = 0, RS_Y = 0;
  void close();

 public slots:
  void onReadyRead();

 private:
  QTcpSocket ts;
  QByteArray buffer;
};

#endif  // NSCONTROLLER_CFW_H
