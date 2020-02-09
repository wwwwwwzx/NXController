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

#ifndef INPUTTABLE_H
#define INPUTTABLE_H
#include <QKeyEvent>

struct inputtable {
  int A = Qt::Key_A;
  int B = Qt::Key_S;
  int X = Qt::Key_Z;
  int Y = Qt::Key_X;
  int L = Qt::Key_Q;
  int R = Qt::Key_W;
  int ZL = Qt::Key_1;
  int ZR = Qt::Key_2;
  int LS = Qt::Key_3;
  int RS = Qt::Key_4;
  int Home = Qt::Key_B;
  int Capture = Qt::Key_V;
  int Plus = Qt::Key_N;
  int Minus = Qt::Key_M;

  int D_Left = Qt::Key_F;
  int D_Right = Qt::Key_H;
  int D_Up = Qt::Key_T;
  int D_Down = Qt::Key_G;
  int LS_Left = Qt::Key_Left;
  int LS_Right = Qt::Key_Right;
  int LS_Up = Qt::Key_Up;
  int LS_Down = Qt::Key_Down;
  int RS_Left = Qt::Key_J;
  int RS_Right = Qt::Key_L;
  int RS_Up = Qt::Key_I;
  int RS_Down = Qt::Key_K;

  int Mouse_Left = Qt::Key_Z;
  int Mouse_Right = Qt::Key_X;
  int Mouse_Middle = Qt::Key_S;
};
Q_DECLARE_METATYPE(inputtable)

QDataStream& operator<<(QDataStream& out, const inputtable& v);
QDataStream& operator>>(QDataStream& in, inputtable& v);
#endif  // INPUTTABLE_H
