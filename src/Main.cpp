// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 05/07/2020.

#include "Main.h"

int main() {
    if (X_SERVER) {
        setenv("DISPLAY", "127.0.0.1:0", true);
    }

    Map map(Size(5, 3));

    map.setParticle(MapElem(new SandParticle()), Position(1, 2));

    // Game game(map, new Window(Size(800, 600), "Dust"));
    Game game(map, new Console());

    bool graceful = true;

    try {
        game.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        graceful = false;
    }

    if (graceful) {
        std::cout << "Program ended properly" << std::endl;
    }

    return graceful ? EXIT_SUCCESS : EXIT_FAILURE;
}
