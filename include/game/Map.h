// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Map
 */
// Created by Romain on 06/07/2020.

#ifndef DUST_MAP_H
#define DUST_MAP_H

#include <memory>
#include <stdexcept>

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
     * Colonne de la game
     */
    typedef std::unique_ptr<MapElem[]> MapCol;

public:
    /**
     * Constructeur
     * @param width Largeur
     * @param height Hauteur
     */
    explicit Map(const Size& size);

    /**
     * Destructeur
     */
    ~Map();

    /**
     * Récupère la largeur
     * @return Largeur
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
     * @throws invalid_argument Si la position est invalide
     * @return Particule [row, col]
     */
    [[nodiscard]] MapElem& getParticle(const Position& pos) const;

    /**
     * Crée une particule
     *
     * @param particle Particule
     * @throws invalid_argument Si la position est invalide
     * @param pos Position
     */
    void setParticle(const MapElem& particle, const Position& pos);

    /**
     * Échange deux particules
     *
     * @param pos1 Position 1
     * @param pos2 Position 2
     * @throws invalid_argument Si la position est invalide
     */
    void swapParticles(const Position& pos1, const Position& pos2);

    /**
     * Supprime une particule
     *
     * @param pos Position
     * @throws invalid_argument Si la position est invalide
     */
    void removeParticle(const Position& pos);

    /**
     * Cellule vide ou non
     *
     * @param pos Position
     * @return Vide ou non
     */
    [[nodiscard]] bool isEmpty(const Position& pos) const;

    /**
     * Position valide ou non
     *
     * @param pos Position
     * @return Valide ou non
     */
    [[nodiscard]] bool isValidPosition(const Position& pos) const;
private:
    /**
     * Taille de la game
     */
    Position size;

    /**
     * Tableau 2D de pointeurs de particules
     */
    std::unique_ptr<MapCol[]> particles;
};

#endif //DUST_MAP_H
