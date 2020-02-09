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

#include "buttonconfig.h"
#include "ui_buttonconfig.h"
#include "inputtable.h"
#include <QSettings>
#include <QKeyEvent>

buttonconfig::buttonconfig(QWidget* parent) : QDialog(parent), ui(new Ui::buttonconfig) {
  ui->setupUi(this);
  QSettings setting;
  auto table = setting.value("settings/keyconfig", qVariantFromValue(config));
  if (table.isValid())
    config = table.value<inputtable>();
  loadsettings();
}

buttonconfig::~buttonconfig() {
  delete ui;
}

void buttonconfig::on_buttonBox_accepted() {
  QSettings setting;
  setting.setValue("settings/keyconfig", qVariantFromValue(config));
}

void buttonconfig::on_B_Default_clicked() {
  inputtable newconfig;
  config = newconfig;
  loadsettings();
}

void buttonconfig::loadsettings() {
  ui->K_A->setText(QKeySequence(config.A).toString(QKeySequence::NativeText));
  ui->K_B->setText(QKeySequence(config.B).toString(QKeySequence::NativeText));
  ui->K_X->setText(QKeySequence(config.X).toString(QKeySequence::NativeText));
  ui->K_Y->setText(QKeySequence(config.Y).toString(QKeySequence::NativeText));
  ui->K_L->setText(QKeySequence(config.L).toString(QKeySequence::NativeText));
  ui->K_R->setText(QKeySequence(config.R).toString(QKeySequence::NativeText));
  ui->K_ZL->setText(QKeySequence(config.ZL).toString(QKeySequence::NativeText));
  ui->K_ZR->setText(QKeySequence(config.ZR).toString(QKeySequence::NativeText));
  ui->K_LS->setText(QKeySequence(config.LS).toString(QKeySequence::NativeText));
  ui->K_RS->setText(QKeySequence(config.RS).toString(QKeySequence::NativeText));
  ui->K_Home->setText(QKeySequence(config.Home).toString(QKeySequence::NativeText));
  ui->K_Capture->setText(QKeySequence(config.Capture).toString(QKeySequence::NativeText));
  ui->K_Plus->setText(QKeySequence(config.Plus).toString(QKeySequence::NativeText));
  ui->K_Minus->setText(QKeySequence(config.Minus).toString(QKeySequence::NativeText));

  ui->K_D_Up->setText(QKeySequence(config.D_Up).toString(QKeySequence::NativeText));
  ui->K_D_Down->setText(QKeySequence(config.D_Down).toString(QKeySequence::NativeText));
  ui->K_D_Left->setText(QKeySequence(config.D_Left).toString(QKeySequence::NativeText));
  ui->K_D_Right->setText(QKeySequence(config.D_Right).toString(QKeySequence::NativeText));
  ui->K_LS_Up->setText(QKeySequence(config.LS_Up).toString(QKeySequence::NativeText));
  ui->K_LS_Down->setText(QKeySequence(config.LS_Down).toString(QKeySequence::NativeText));
  ui->K_LS_Left->setText(QKeySequence(config.LS_Left).toString(QKeySequence::NativeText));
  ui->K_LS_Right->setText(QKeySequence(config.LS_Right).toString(QKeySequence::NativeText));
  ui->K_RS_Up->setText(QKeySequence(config.RS_Up).toString(QKeySequence::NativeText));
  ui->K_RS_Down->setText(QKeySequence(config.RS_Down).toString(QKeySequence::NativeText));
  ui->K_RS_Left->setText(QKeySequence(config.RS_Left).toString(QKeySequence::NativeText));
  ui->K_RS_Right->setText(QKeySequence(config.RS_Right).toString(QKeySequence::NativeText));

  ui->K_Mouse_Left->setText(QKeySequence(config.Mouse_Left).toString(QKeySequence::NativeText));
  ui->K_Mouse_Right->setText(QKeySequence(config.Mouse_Right).toString(QKeySequence::NativeText));
  ui->K_Mouse_Middle->setText(QKeySequence(config.Mouse_Middle).toString(QKeySequence::NativeText));
}

void buttonconfig::on_K_A_textChanged(const QString& newtext) {
  config.A = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_B_textChanged(const QString& newtext) {
  config.B = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_X_textChanged(const QString& newtext) {
  config.X = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_Y_textChanged(const QString& newtext) {
  config.Y = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_L_textChanged(const QString& newtext) {
  config.L = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_R_textChanged(const QString& newtext) {
  config.R = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_ZL_textChanged(const QString& newtext) {
  config.ZL = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_ZR_textChanged(const QString& newtext) {
  config.ZR = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_LS_textChanged(const QString& newtext) {
  config.LS = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_RS_textChanged(const QString& newtext) {
  config.RS = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_Home_textChanged(const QString& newtext) {
  config.Home = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_Capture_textChanged(const QString& newtext) {
  config.Capture = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_Plus_textChanged(const QString& newtext) {
  config.Plus = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_Minus_textChanged(const QString& newtext) {
  config.Minus = QKeySequence(newtext)[0];
}

void buttonconfig::on_K_D_Up_textChanged(const QString& newtext) {
  config.D_Up = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_D_Down_textChanged(const QString& newtext) {
  config.D_Down = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_D_Left_textChanged(const QString& newtext) {
  config.D_Left = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_D_Right_textChanged(const QString& newtext) {
  config.D_Right = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_LS_Up_textChanged(const QString& newtext) {
  config.LS_Up = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_LS_Down_textChanged(const QString& newtext) {
  config.LS_Down = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_LS_Left_textChanged(const QString& newtext) {
  config.LS_Left = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_LS_Right_textChanged(const QString& newtext) {
  config.LS_Right = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_RS_Up_textChanged(const QString& newtext) {
  config.RS_Up = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_RS_Down_textChanged(const QString& newtext) {
  config.RS_Down = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_RS_Left_textChanged(const QString& newtext) {
  config.RS_Left = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_RS_Right_textChanged(const QString& newtext) {
  config.RS_Right = QKeySequence(newtext)[0];
}

void buttonconfig::on_K_Mouse_Left_textChanged(const QString& newtext) {
  config.Mouse_Left = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_Mouse_Right_textChanged(const QString& newtext) {
  config.Mouse_Right = QKeySequence(newtext)[0];
}
void buttonconfig::on_K_Mouse_Middle_textChanged(const QString& newtext) {
  config.Mouse_Middle = QKeySequence(newtext)[0];
}
