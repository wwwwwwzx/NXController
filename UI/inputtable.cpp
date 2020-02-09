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

#include "inputtable.h"

QDataStream& operator<<(QDataStream& out, const inputtable& v) {
  out << v.A << v.B << v.X << v.Y << v.L << v.R << v.ZL << v.ZR << v.LS << v.RS << v.Home << v.Capture << v.Plus << v.Minus;
  out << v.D_Up << v.D_Down << v.D_Left << v.D_Right;
  out << v.LS_Up << v.LS_Down << v.LS_Left << v.LS_Right;
  out << v.RS_Up << v.RS_Down << v.RS_Left << v.RS_Right;
  out << v.Mouse_Left << v.Mouse_Right << v.Mouse_Middle;
  return out;
}

QDataStream& operator>>(QDataStream& in, inputtable& v) {
  in >> v.A >> v.B >> v.X >> v.Y >> v.L >> v.R >> v.ZL >> v.ZR >> v.LS >> v.RS >> v.Home >> v.Capture >> v.Plus >> v.Minus;
  in >> v.D_Up >> v.D_Down >> v.D_Left >> v.D_Right;
  in >> v.LS_Up >> v.LS_Down >> v.LS_Left >> v.LS_Right;
  in >> v.RS_Up >> v.RS_Down >> v.RS_Left >> v.RS_Right;
  in >> v.Mouse_Left >> v.Mouse_Right >> v.Mouse_Middle;
  return in;
}
