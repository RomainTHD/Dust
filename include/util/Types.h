// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Type Position
 */
// Created by Romain on 13/07/2020.

#ifndef DUST_TYPES_H
#define DUST_TYPES_H

#include <utility>
#include <cstddef>

/**
 * Position
 */
typedef std::pair<long, long> Position;

/**
 * Taille
 */
typedef std::pair<size_t, size_t> Size;

/**
 * Namespace des fonctions associées aux positions
 */
namespace position {
    /**
     * Getter ligne
     *
     * @param pos Position
     * @return Ligne
     */
    long getRow(const Position &pos);

    /**
     * Getter colonne
     *
     * @param pos Position
     * @return Colonne
     */
    long getCol(const Position &pos);
}

#endif //DUST_TYPES_H
