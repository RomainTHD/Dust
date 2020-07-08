// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 05/07/2020.

#include "Main.h"

int main() {
    if (X_SERVER) {
        setenv("DISPLAY", "127.0.0.1:0", true);
    }

    Map map(10, 10);

    map.setParticle(new SandParticle(), std::pair<size_t, size_t>(1, 5));

    Window window(map, std::pair<size_t, size_t>(800, 600), "Dust");

    bool graceful = true;

    try {
        window.run();
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
