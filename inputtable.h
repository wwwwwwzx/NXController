#ifndef INPUTTABLE_H
#define INPUTTABLE_H
#include <QKeyEvent>

class inputtable {
 public:
  inputtable();
  Qt::Key A = Qt::Key_A;
  Qt::Key B = Qt::Key_S;
  Qt::Key X = Qt::Key_Z;
  Qt::Key Y = Qt::Key_X;
  Qt::Key L = Qt::Key_Q;
  Qt::Key R = Qt::Key_W;
  Qt::Key ZL = Qt::Key_1;
  Qt::Key ZR = Qt::Key_2;
  Qt::Key LS = Qt::Key_3;
  Qt::Key RS = Qt::Key_4;
  Qt::Key Home = Qt::Key_B;
  Qt::Key Capture = Qt::Key_V;
  Qt::Key Plus = Qt::Key_N;
  Qt::Key Minus = Qt::Key_M;

  Qt::Key D_Up = Qt::Key_T;
  Qt::Key D_Down = Qt::Key_G;
  Qt::Key D_Left = Qt::Key_F;
  Qt::Key D_Right = Qt::Key_H;
  Qt::Key LS_Left = Qt::Key_Left;
  Qt::Key LS_Right = Qt::Key_Right;
  Qt::Key LS_Up = Qt::Key_Up;
  Qt::Key LS_Down = Qt::Key_Down;
  Qt::Key RS_Left = Qt::Key_J;
  Qt::Key RS_Right = Qt::Key_L;
  Qt::Key RS_Up = Qt::Key_I;
  Qt::Key RS_Down = Qt::Key_K;
};

#endif  // INPUTTABLE_H
