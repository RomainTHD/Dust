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

    std::chrono::time_point<std::chrono::system_clock> lastUpdate = std::chrono::system_clock::now();

    while (view->isRunning()) {
        view->processEvents(map);

        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

        const float diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdate).count();

        if (diff > 1000.0f / UPDATES_PER_SECOND) {
            update();
            lastUpdate = std::chrono::system_clock::now();
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
