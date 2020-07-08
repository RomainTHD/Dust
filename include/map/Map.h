// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Map
 */
// Created by Romain on 06/07/2020.

#ifndef DUST_MAP_H
#define DUST_MAP_H

#include <utility>
#include <cstddef>
#include <vector>

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
    [[nodiscard]] size_t getWidth() const;

    /**
     * Récupère la hauteur
     * @return Hauteur
     */
    [[nodiscard]] size_t getHeight() const;

    /**
     * récupère une particule
     *
     * @param pos Position [row, col]
     * @return Particule [row, col]
     */
    [[nodiscard]] Particle* getParticle(std::pair<size_t, size_t> pos) const;

    /**
     * Crée une particule
     *
     * @param particle Particule
     * @param pos Position
     */
    void setParticle(Particle* particle, std::pair<size_t, size_t> pos);
private:
    /**
     * Taille de la map
     */
    std::pair<size_t, size_t> size;

    /**
     * Liste des particules
     */
    std::vector<std::vector<Particle*>> particles;
};


#endif //DUST_MAP_H
