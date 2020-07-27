// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 16/07/2020.

#include "util/Types.h"

long position::getRow(const Position &pos) {
    return pos.first;
}

long position::getCol(const Position &pos) {
    return pos.second;
}
