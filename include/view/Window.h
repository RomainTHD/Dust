// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#ifndef DUST_WINDOW_H
#define DUST_WINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "map/Map.h"

#define BACKGROUND_COLOR sf::Color::Blue

class Window {
public:
    /**
     * Constructeur
     *
     * @param map Map
     * @param size Taille initiale
     * @param title Titre
     */
    Window(const Map& map, std::pair<size_t, size_t> size, const std::string& title);

    /**
     * Destructeur
     */
    ~Window() = default;

    /**
     * Lance la fenêtre
     *
     * @throws runtime_error Si la fenêtre est déjà ouverte
     */
    void run();

private:
    /**
     * Gère les events
     */
    void processEvents();

    /**
     * Met à jour
     */
    void update();

    /**
     * Affiche
     */
    void render();

    /**
     * Gère les entrées clavier
     *
     * @param key Touche
     * @param pressed Enfoncée ou relâchée
     */
    void handleInput(const sf::Keyboard::Key& key, bool pressed);

    /**
     * Fenêtre
     */
    sf::RenderWindow renderWindow;

    /**
     * Map
     */
    const Map& map;

    /**
     * Lancé ou non
     */
    bool running;
};

#endif //DUST_WINDOW_H
