// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 05/07/2020.

#include "view/Console.h"
#include "Main.h"

int main() {
    if (X_SERVER) {
        setenv("DISPLAY", "127.0.0.1:0", true);
    }

    Map map(Size(5, 3));

    map.setParticle(MapElem(new SandParticle()), Position(1, 2));

    // Window window(map, Size(800, 600), "Dust");

    bool graceful = true;

    view::displayMapToConsole(map);

    try {
        // window.run();
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
