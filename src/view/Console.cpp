// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 16/07/2020.

#include "view/Console.h"

namespace {
    void displayBorderRow(const Map& map, bool up) {
        if (up) {
            std::cout << "┌";
        }
        else {
            std::cout << "└";
        }

        for (size_t i=0; i < map.getNbCols()-1; i++) {
            std::cout << "───";

            if (up) {
                std::cout << "┬";
            }
            else {
                std::cout << "┴";
            }
        }

        std::cout << "───";

        if (up) {
            std::cout << "┐";
        }
        else {
            std::cout << "┘";
        }

        std::cout << std::endl;
    }
}

void view::displayMapToConsole(const Map& map) {
    displayBorderRow(map, true);

    for (size_t row=0; row < map.getNbRows(); row++) {
        for (size_t col=0; col < map.getNbCols(); col++) {
            if (col == 0) {
                std::cout << "│";
            }

            std::cout << " ";

            if (map.isEmpty(Position(row, col))) {
                std::cout << " ";
            }
            else {
                std::cout << "█";
            }

            std::cout << " ";

            if (col != map.getNbCols()-1) {
                std::cout << "│";
            }
        }

        std::cout << "│" << std::endl;

        if (row != map.getNbRows()-1) {
            std::cout << "├";

            for (size_t i=0; i < map.getNbCols()-1; i++) {
                std::cout << "───┼";
            }

            std::cout << "───";

            std::cout << "┤" << std::endl;

        }
    }

    displayBorderRow(map, false);
}
