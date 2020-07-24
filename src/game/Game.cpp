// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 24/07/2020.

#include "game/Game.h"

Game::Game(Map &map, GenericView *view) :
    map(map),
    view(view),
    frameCount(0)
{}

Game::~Game() {
    delete view;
}

void Game::run() {
    if (running) {
        throw std::runtime_error("Game already running");
    }

    running = true;

    const int frameTarget = std::max(FRAMERATE / UPDATES_PER_SECOND, 1);

    while (view->isRunning()) {
        view->processEvents(map);

        if (frameCount % frameTarget == 0) {
            update();
        }

        view->render(map);

        frameCount++;
    }
}

void Game::update() {
    for (unsigned int row=0; row < map.getHeight(); row++) {
        for (unsigned int col = 0; col < map.getWidth(); col++) {
            const Position pos(row, col);

            if (!map.isEmpty(pos)) {
                MapElem particle = map.getParticle(pos);

                particle->update();

                if (particle->hasChanged()) {

                }
            }
        }
    }
}
