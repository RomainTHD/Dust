// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Affichage console
 */
// Created by Romain on 16/07/2020.

#ifndef DUST_CONSOLE_H
#define DUST_CONSOLE_H

#include <cstdio>

#include "map/Map.h"

/**
 * Namespace contenant diverses fonctions de vue
 */
namespace view {
    /**
     * Affiche la map dans la console
     *
     * @param map Map
     */
    void displayMapToConsole(const Map& map);
}

#endif //DUST_CONSOLE_H
