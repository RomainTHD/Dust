// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Map
 */
// Created by Romain on 06/07/2020.

#ifndef DUST_MAP_H
#define DUST_MAP_H

#include <utility>
#include <cstddef>

#include "Map.fwd.h"
#include "particles/Particle.fwd.h"

/**
 * Map
 */
class Map {
public:
    /**
     * Constructeur
     * @param width Largeur
     * @param height Hauteur
     */
    Map(size_t width, size_t height);

    /**
     * Destructeur
     */
    ~Map() = default;

    /**
     * Récupère la largeur
     * @return Largeur
     */
    [[nodiscard]] size_t getWidth();

    /**
     * Récupère la hauteur
     * @return Hauteur
     */
    [[nodiscard]] size_t getHeight();

private:
    /**
     * Taille de la map
     */
    std::pair<size_t, size_t> size;
};


#endif //DUST_MAP_H
