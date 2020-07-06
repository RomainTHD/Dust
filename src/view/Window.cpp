// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "view/Window.h"

Window::Window(const Map& m, std::pair<size_t, size_t> size, const std::string& title) :
    running(false),
    map(m) {
    renderWindow.create(sf::VideoMode(size.first, size.second), title);
}

void Window::run() {
    if (running) {
        throw std::runtime_error("Window already opened");
    }

    running = true;

    while (renderWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Window::processEvents() {
    sf::Event event {};

    while (renderWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handleInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handleInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                renderWindow.close();
                break;

            default:
                break;
        }
    }
}

void Window::update() {

}

void Window::render() {
    renderWindow.clear(BACKGROUND_COLOR);

    /*
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;

    float cellWidth = windowWidth / (float) map->getNbCols();
    float cellHeight = windowHeight / (float) map->getNbRows();

    sf::RectangleShape shape(sf::Vector2f(cellWidth, cellHeight));

    shape.setOutlineThickness(0);

    for (auto iter = map->iterCell(); iter != map->iterEnd(); iter++) {
        shape.setPosition(iter.getCol()*cellWidth, iter.getRow()*cellHeight);
        shape.setFillColor(sf::Color::Green);

        window.draw(shape);
    }

    const float thickness = 5;

    sf::RectangleShape line(sf::Vector2f(cellWidth + thickness, thickness));
    line.setFillColor(sf::Color::Red);

    for (auto iter = map->iterWallHoriz(); iter != map->iterEnd(); iter++) {
        if (iter.getWall()->isFilled()) {
            float x = cellWidth * iter.getCol() - thickness/2;
            float y = cellHeight * ceilf(iter.getRow()) - thickness/2;

            line.setPosition(sf::Vector2f(x, y));
            window.draw(line);
        }
    }

    line.setSize(sf::Vector2f(thickness, cellHeight + thickness));

    for (auto iter = map->iterWallVert(); iter != map->iterEnd(); iter++) {
        if (iter.getWall()->isFilled()) {
            float x = cellWidth * ceilf(iter.getCol()) - thickness/2;
            float y = cellHeight * iter.getRow() - thickness/2;

            line.setPosition(sf::Vector2f(x, y));
            window.draw(line);
        }
    }
     */

    renderWindow.display();
}

void Window::handleInput(const sf::Keyboard::Key& key, bool pressed) {

}
