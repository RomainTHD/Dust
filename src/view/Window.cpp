// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "view/Window.h"

Window::Window(const Map& m, std::pair<size_t, size_t> size, const std::string& title) :
    running(false),
    map(m) {
    renderWindow.create(sf::VideoMode(size.first, size.second), title);
    renderWindow.setFramerateLimit(FRAMERATE);
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

            case sf::Event::Resized:
                handleResize(event.size);
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

    const float windowWidth = renderWindow.getSize().x;
    const float windowHeight = renderWindow.getSize().y;

    const float cellWidth = windowWidth / (float) map.getWidth();
    const float cellHeight = windowHeight / (float) map.getHeight();

    sf::RectangleShape shape(sf::Vector2f(cellWidth, cellHeight));
    shape.setPosition(0, 0);

    shape.setOutlineThickness(OUTLINE_THICKNESS);
    shape.setOutlineColor(BACKGROUND_COLOR);

    for (unsigned int row=0; row < map.getHeight(); row++) {
        for (unsigned int col=0; col < map.getWidth(); col++) {
            // std::cout << cellWidth << ' ' << windowWidth <<' '<< ((float) col) * cellWidth << '\n';

            // shape.setPosition(((float) col) * cellWidth, ((float) row) * cellHeight);

            shape.setFillColor(sf::Color::Green);

            renderWindow.draw(shape);

            shape.move(cellWidth, 0);

        }

        shape.setPosition(0, shape.getPosition().y);
        shape.move(0, cellHeight);
    }

    renderWindow.display();
}

void Window::handleInput(const sf::Keyboard::Key& key, bool pressed) {

}

void Window::handleResize(sf::Event::SizeEvent& size) {
    const float cellWidth = (float) size.width / (float) map.getWidth();
    const float cellHeight = (float) size.height / (float) map.getHeight();

    if (cellWidth > 2*OUTLINE_THICKNESS + 1 && cellHeight > 2 * OUTLINE_THICKNESS + 1) {
        // renderWindow.setSize(sf::Vector2u(size.width, size.height));
    }
    else {
        // renderWindow.setSize(sf::Vector2u(1000, 1000));
    }
}
