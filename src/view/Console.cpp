// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 16/07/2020.

#include "view/Console.h"

using namespace position;

namespace {
    void displayBorderRowToConsole(const Map& map, bool up) {
        std::cout << (up ? UP_LEFT : DOWN_LEFT);

        for (size_t col=0; col < map.getNbCols()-1; col++) {
            std::cout << HORIZONTAL HORIZONTAL HORIZONTAL << (up ? CROSS_DOWN : CROSS_UP);
        }

        std::cout << HORIZONTAL HORIZONTAL HORIZONTAL << (up ? UP_RIGHT : DOWN_RIGHT) << std::endl;
    }

    void displayCellToConsole(const Map& map, Position p) {
        if (getCol(p) == 0) {
            std::cout << VERTICAL;
        }

        std::cout << SPACE;

        if (map.isEmpty(p)) {
            std::cout << EMPTY;
        }
        else {
            std::cout << FULL;
        }

        std::cout << SPACE;

        if ((unsigned) getCol(p) != map.getNbCols()-1) {
            std::cout << VERTICAL;
        }
    }

    void displayHorizontalRowToConsole(const Map& map, unsigned int row) {
        std::cout << VERTICAL << std::endl;

        if (row != map.getNbRows()-1) {
            std::cout << CROSS_RIGHT;

            for (size_t i=0; i < map.getNbCols()-1; i++) {
                std::cout << HORIZONTAL HORIZONTAL HORIZONTAL CROSS;
            }

            std::cout << HORIZONTAL HORIZONTAL HORIZONTAL CROSS_LEFT << std::endl;
        }
    }
}

void view::displayMapToConsole(const Map& map) {
    displayBorderRowToConsole(map, true);

    for (size_t row=0; row < map.getNbRows(); row++) {
        for (size_t col=0; col < map.getNbCols(); col++) {
            displayCellToConsole(map, Position(row, col));
        }

        displayHorizontalRowToConsole(map, row);
    }

    displayBorderRowToConsole(map, false);
}
