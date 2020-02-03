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
  QSettings setting("config.ini", QSettings::IniFormat);
  auto table = setting.value("settings/keyconfig", qVariantFromValue(config));
  if (table.isValid())
    config = table.value<inputtable>();
  ui->K_A->setText(QKeySequence(config.A).toString(QKeySequence::NativeText));
  ui->K_B->setText(QKeySequence(config.B).toString(QKeySequence::NativeText));
  ui->K_X->setText(QKeySequence(config.X).toString(QKeySequence::NativeText));
  ui->K_Y->setText(QKeySequence(config.Y).toString(QKeySequence::NativeText));
}

buttonconfig::~buttonconfig() {
  delete ui;
}

void buttonconfig::on_buttonBox_accepted() {
  QSettings setting("config.ini", QSettings::IniFormat);
  setting.setValue("settings/keyconfig", qVariantFromValue(config));
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
