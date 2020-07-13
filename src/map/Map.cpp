// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "map/Map.h"

#include <utility>

Map::Map(Size size) :
    size(size.first, size.second)
{
    particles = std::unique_ptr<MapCol[]>(new MapCol[getNbRows()]);

    for (size_t row=0; row<getNbRows(); row++) {
        MapCol mapCol = MapCol(new MapElem[getNbCols()]);

        for (size_t col=0; col<getNbCols(); col++) {
            mapCol[col] = nullptr;
        }

        particles[row] = std::move(mapCol);
    }
}

Map::~Map() = default;

size_t Map::getWidth() const {
    return Map::getNbCols();
}

size_t Map::getNbCols() const {
    return size.first;
}

size_t Map::getHeight() const {
    return Map::getNbRows();
}

size_t Map::getNbRows() const {
    return size.second;
}

MapElem Map::getParticle(Position pos) const {
    return particles[pos.first][pos.second];
}

void Map::setParticle(MapElem particle, Position pos) {
    particles[pos.first][pos.second] = std::move(particle);
}

bool Map::isEmpty(Position pos) const {
    return particles[pos.first][pos.second] == nullptr;
}
