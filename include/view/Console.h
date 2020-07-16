// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Affichage console
 */
// Created by Romain on 16/07/2020.

#ifndef DUST_CONSOLE_H
#define DUST_CONSOLE_H

#define UP_LEFT "┌"
#define UP_RIGHT "┐"
#define DOWN_LEFT "└"
#define DOWN_RIGHT "┘"

#define CROSS "┼"
#define CROSS_DOWN "┬"
#define CROSS_UP "┴"
#define CROSS_LEFT "┤"
#define CROSS_RIGHT "├"

#define HORIZONTAL "─"
#define VERTICAL "│"

#define SPACE " "

#define EMPTY " "
#define FULL "█"

#include <cstdio>

#include "map/Map.h"
#include "util/Types.h"

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
