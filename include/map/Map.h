// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Map
 */
// Created by Romain on 06/07/2020.

#ifndef DUST_MAP_H
#define DUST_MAP_H

#include <cstddef>
#include <vector>
#include <memory>

#include "util/Types.h"
#include "Map.fwd.h"
#include "particles/Particle.h"

/**
 * Élément de la map
 */
typedef std::shared_ptr<Particle> MapElem;

/**
 * Map
 */
class Map {
    /**
     * Colonne de la map
     */
    typedef std::unique_ptr<MapElem[]> MapCol;

public:
    /**
     * Constructeur
     * @param width Largeur
     * @param height Hauteur
     */
    Map(Size size);

    /**
     * Destructeur
     */
    ~Map();

    /**
     * Récupère la largeur
     * @return Largeur
     * @deprecated
     */
    [[nodiscard]] size_t getWidth() const;

    /**
     * Récupère la largeur (nombre de colonnes)
     * @return Largeur
     */
    [[nodiscard]] size_t getNbCols() const;

    /**
     * Récupère la hauteur
     * @return Hauteur
     * @deprecated
     */
    [[nodiscard]] size_t getHeight() const;

    /**
     * Récupère la hauteur (nombre de lignes)
     * @return Hauteur
     */
    [[nodiscard]] size_t getNbRows() const;

    /**
     * récupère une particule
     *
     * @param pos Position [row, col]
     * @return Particule [row, col]
     */
    [[nodiscard]] MapElem getParticle(Position pos) const;

    /**
     * Crée une particule
     *
     * @param particle Particule
     * @param pos Position
     */
    void setParticle(MapElem particle, Position pos);

    [[nodiscard]] bool isEmpty(Position pos) const;
private:
    /**
     * Taille de la map
     */
    Position size;

    /**
     * Tableau 2D de pointeurs de particules
     */
    std::unique_ptr<MapCol[]> particles;
};

#endif //DUST_MAP_H

