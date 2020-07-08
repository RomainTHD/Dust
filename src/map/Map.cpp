// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "map/Map.h"

Map::Map(size_t width, size_t height) :
    size(width, height)
    {
        particles.reserve(height);

        for (unsigned int row=0; row < height; row++) {
            std::vector<Particle*> particlesRow;
            particlesRow.reserve(width);

            for (unsigned int col=0; col < width; col++) {
                particlesRow.push_back(nullptr);
            }

            particles.push_back(particlesRow);
        }
    }

size_t Map::getWidth() const {
    return size.first;
}

size_t Map::getHeight() const {
    return size.second;
}

Particle *Map::getParticle(std::pair<size_t, size_t> pos) const {
    return particles.at(pos.first).at(pos.second);
}

void Map::setParticle(Particle *particle, std::pair<size_t, size_t> pos) {
    particles.at(pos.first).at(pos.second) = particle;
}
