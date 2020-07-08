// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#ifndef DUST_WINDOW_H
#define DUST_WINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "map/Map.h"
#include "particles/Particle.h"

#define BACKGROUND_COLOR sf::Color::Black
#define OUTLINE_THICKNESS 1
#define FRAMERATE 60
#define ENABLE_VSYNC true

/**
 * Gestion de la fenêtre
 */
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
     * Quitte
     */
    void exit();

    /**
     * Gère les entrées clavier
     *
     * @param key Touche
     * @param pressed Bouton enfoncé ou relâché
     */
    void handleInput(const sf::Event::KeyEvent& key, bool pressed);

    /**
     * Gère les appuis souris
     *
     * @param mouse Souris
     * @param pressed Bouton enfoncé ou relâché
     */
    void handleMouse(const sf::Event::MouseButtonEvent& mouse, bool pressed);

    /**
     * Gère le redimensionnement de la fenêtre
     *
     * @param size Event de resize
     */
    void handleResize(sf::Event::SizeEvent& size);

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
    inline static bool running = false;
};

#endif //DUST_WINDOW_H
