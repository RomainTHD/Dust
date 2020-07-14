// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "map/Map.h"

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
    if (isValidPosition(pos)) {
        return particles[pos.first][pos.second];
    }
    else {
        throw std::invalid_argument("Position invalide");
    }
}

void Map::setParticle(MapElem particle, Position pos) {
    if (isValidPosition(pos)) {
        particles[pos.first][pos.second] = std::move(particle);
    }
    else {
        throw std::invalid_argument("Position invalide");
    }
}

void Map::swapParticles(Position pos1, Position pos2) {
    if (isValidPosition(pos1) && isValidPosition(pos2)) {
        std::swap(particles[pos1.first][pos1.second], particles[pos2.first][pos2.second]);
    }
    else {
        throw std::invalid_argument("Position invalide");
    }
}

void Map::removeParticle(Position pos) {
    if (isValidPosition(pos)) {
        particles[pos.first][pos.second] = nullptr;
    }
    else {
        throw std::invalid_argument("Position invalide");
    }
}

bool Map::isEmpty(Position pos) const {
    return particles[pos.first][pos.second] == nullptr;
}

bool Map::isValidPosition(Position pos) const {
    return pos.first > 0 && static_cast<size_t>(pos.first) < getNbRows()
        && pos.second > 0 && static_cast<size_t>(pos.second) < getNbCols();
}
