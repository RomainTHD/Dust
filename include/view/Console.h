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
#include <chrono>
#include <thread>

#include "game/Map.h"
#include "util/Types.h"
#include "GenericView.h"
#include "Config.h"

/**
 * Affiche le jeu dans la console
 */
class Console : public GenericView {
public:
    /**
     * Destructeur
     */
    ~Console() override = default;

    /**
     * Affichage
     *
     * @param map Map
     */
    void render(const Map& map) override;

    /**
     * Si la vue tourne encore ou non
     *
     * @return Running ou non
     */
    [[nodiscard]] bool isRunning() const override;
};

#endif //DUST_CONSOLE_H
