// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "map/Map.h"

Map::Map(size_t width, size_t height) :
    size(width, height)
    {}

size_t Map::getWidth() const {
    return size.first;
}

size_t Map::getHeight() const {
    return size.second;
}
