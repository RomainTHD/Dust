// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Gestion de la fenêtre
 */
// Created by Romain on 06/07/2020.

#ifndef DUST_WINDOW_H
#define DUST_WINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "view/Color.h"
#include "util/Types.h"
#include "game/Map.h"
#include "particles/Particle.h"
#include "particles/SandParticle.h"
#include "Config.h"
#include "GenericView.h"

/**
 * Gestion de la fenêtre
 */
class Window : public GenericView {
public:
    /**
     * Constructeur
     *
     * @param size Taille initiale
     * @param title Titre
     */
    Window(const Position& size, const std::string& title);

    /**
     * Destructeur
     */
    ~Window() override = default;

private:
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
    void handleInput(Map& map, const sf::Event::KeyEvent& key, bool pressed);

    /**
     * Gère les appuis souris
     *
     * @param mouse Souris
     * @param pressed Bouton enfoncé ou relâché
     */
    void handleMouse(Map& map, const sf::Event::MouseButtonEvent& mouse, bool pressed);

    /**
     * Gère le redimensionnement de la fenêtre
     *
     * @param size Event de resize
     */
    void handleResize(const Map& map, sf::Event::SizeEvent& size);

    /**
     * Fenêtre
     */
    sf::RenderWindow renderWindow;

    /**
     * Gestion des évènements
     *
     * @param map Map
     */
    void processEvents(Map &map) override;

    /**
     * Affichage
     *
     * @param map Map
     */
    void render(const Map& map) override;

    /**
     * Si la vue tourne encore ou non
     *
     * @return Running ou non
     */
    [[nodiscard]] bool isRunning() const override;
};

#endif //DUST_WINDOW_H
