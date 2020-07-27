// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 08/07/2020.

#include "view/Color.h"

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
    r(r),
    g(g),
    b(b),
    a(a)
    {
}

Color::Color(std::string hex) {
    if (hex.length() > 0) {
        if (hex[0] == '#') {
            hex = hex.substr(1);
        }
        else if (hex[0] == '0' && hex.length() > 1 && hex[1] == 'x') {
            hex = hex.substr(2);
        }

        if (hex.length() >= 6) {
            r = std::strtoul(hex.substr(0, 2).c_str(), nullptr, 16);
            g = std::strtoul(hex.substr(2, 2).c_str(), nullptr, 16);
            b = std::strtoul(hex.substr(4, 2).c_str(), nullptr, 16);

            if (hex.length() >= 8) {
                a = std::strtoul(hex.substr(6, 2).c_str(), nullptr, 16);
            }
            else {
                a = 255;
            }
        }
        else {
            std::cerr << "Hex trop court";
            r = g = b = a = 0;
        }
    }
}

uint8_t Color::getR() const {
    return r;
}

uint8_t Color::getG() const {
    return g;
}

uint8_t Color::getB() const {
    return b;
}

uint8_t Color::getA() const {
    return a;
}

sf::Color Color::toSFMLColor() const {
    return sf::Color(r, g, b, a);
}
