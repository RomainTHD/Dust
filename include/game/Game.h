// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Jeu général
 */
// Created by Romain on 24/07/2020.

#ifndef DUST_GAME_H
#define DUST_GAME_H

#include "view/GenericView.h"
#include "Map.h"
#include "Config.h"

/**
 * Jeu
 */
class Game {
public:
    /**
     * Constructeur
     *
     * @param map Map jouée
     * @param view Affichage choisi
     */
    Game(Map& map, GenericView* view);

    /**
     * Destructeur
     */
    ~Game();

    /**
     * Lance la simulation
     *
     * @throws runtime_error Si la fenêtre est déjà ouverte
     */
    void run();

private:
    /**
     * Met à jour la simulation
     */
    void update();

    /**
     * Map
     */
    Map& map;

    /**
     * Vue
     */
    GenericView* view;

    /**
     * Nombre de frames
     */
    uintmax_t frameCount;

    /**
     * Jeu déjà lancé ou non
     */
    inline static bool running = false;
};

#endif //DUST_GAME_H
