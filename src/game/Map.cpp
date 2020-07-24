// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "game/Map.h"

Map::Map(const Size& size) :
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

MapElem& Map::getParticle(const Position& pos) const {
    if (isValidPosition(pos)) {
        return particles[pos.first][pos.second];
    }
    else {
        throw std::invalid_argument(
                "Position invalide : ["
                + std::to_string(pos.first)
                + ", "
                + std::to_string(pos.second)
                + "]"
                );
    }
}

void Map::setParticle(const MapElem& particle, const Position& pos) {
    if (isValidPosition(pos)) {
        particles[pos.first][pos.second] = particle;
    }
    else {
        throw std::invalid_argument("Position invalide");
    }
}

void Map::swapParticles(const Position& pos1, const Position& pos2) {
    if (isValidPosition(pos1) && isValidPosition(pos2)) {
        std::swap(particles[pos1.first][pos1.second], particles[pos2.first][pos2.second]);
    }
    else {
        throw std::invalid_argument(
                "Position invalide : ["
                + std::to_string(pos1.first)
                + ", "
                + std::to_string(pos1.second)
                + "], ["
                + std::to_string(pos2.first)
                + ", "
                + std::to_string(pos2.second)
                + "]"
        );
    }
}

void Map::removeParticle(const Position& pos) {
    if (isValidPosition(pos)) {
        particles[pos.first][pos.second] = nullptr;
    }
    else {
        throw std::invalid_argument(
                "Position invalide : ["
                + std::to_string(pos.first)
                + ", "
                + std::to_string(pos.second)
                + "]"
        );
    }
}

bool Map::isEmpty(const Position& pos) const {
    return particles[pos.first][pos.second] == nullptr;
}

bool Map::isValidPosition(const Position& pos) const {
    return pos.first >= 0 && static_cast<size_t>(pos.first) < getNbRows()
        && pos.second >= 0 && static_cast<size_t>(pos.second) < getNbCols();
}
