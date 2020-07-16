// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Gestion des couleurs<br>
 * Couche d'abstraction au dessus de la SFML
 */
// Created by Romain on 08/07/2020.

#ifndef DUST_COLOR_H
#define DUST_COLOR_H

#include <cstdint>
#include <string>
#include <iostream>
#include <SFML/Graphics/Color.hpp>

/**
 * Classe gérant les couleurs<br>
 * Permet une couche d'abstraction en n'utilisant la SFML qu'à partir d'ici
 */
class Color {
public:
    /**
     * Constructeur
     *
     * @param r Rouge
     * @param g Vert
     * @param b Bleu
     * @param a Alpha
     */
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255);

    /**
     * Constructeur pour hexadécimal
     * @param hex Chaine hexadécimale (3 ou 4 octets)
     */
    explicit Color(std::string hex);

    /**
     * Destructeur
     */
    ~Color() = default;

    /**
     * Getter R
     * @return R
     */
    [[nodiscard]] uint8_t getR() const;

    /**
     * Getter G
     * @return G
     */
    [[nodiscard]] uint8_t getG() const;

    /**
     * Getter B
     * @return B
     */
    [[nodiscard]] uint8_t getB() const;

    /**
     * Getter A
     * @return A
     */
    [[nodiscard]] uint8_t getA() const;

    /**
     * Cast vers Color SFML
     * @return Color SFML
     */
    [[nodiscard]] sf::Color toSFMLColor() const;
private:
    /**
     * Composantes RGBA
     */
    uint8_t r, g, b, a;
};

#endif //DUST_COLOR_H
