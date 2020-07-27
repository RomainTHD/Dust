// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "view/Window.h"

Window::Window(const Position& size, const std::string& title) {
    renderWindow.create(sf::VideoMode(size.first, size.second), title);
    renderWindow.setFramerateLimit(FRAMERATE);
#   ifdef VSYNC_MODE
        renderWindow.setVerticalSyncEnabled(VSYNC_MODE);
#   endif
    renderWindow.setMouseCursorVisible(true);
    renderWindow.setKeyRepeatEnabled(true);
}

void Window::processEvents(Map& map) {
    sf::Event event {};

    while (renderWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
                handleInput(map, event.key, event.type == sf::Event::KeyPressed);
                break;

            case sf::Event::MouseButtonPressed:
            case sf::Event::MouseButtonReleased:
                handleMouse(map, event.mouseButton, event.type == sf::Event::MouseButtonPressed);
                break;

            case sf::Event::Closed:
                exit();
                break;

            case sf::Event::Resized:
                handleResize(map, event.size);
                break;

            default:
                break;
        }
    }
}

void Window::render(const Map& map) {
    renderWindow.clear(Color(BACKGROUND_COLOR).toSFMLColor());

    const float cellSize = std::min(
            static_cast<float>(renderWindow.getSize().x) / static_cast<float>(map.getWidth()),
            static_cast<float>(renderWindow.getSize().y) / static_cast<float>(map.getHeight())
    );

    const sf::Vector2f offset = sf::Vector2f(renderWindow.getSize()) - sf::Vector2f(
            static_cast<float>(map.getWidth()) * cellSize,
            static_cast<float>(map.getHeight()) * cellSize
    );

    sf::RectangleShape shape(sf::Vector2f(cellSize, cellSize));

    shape.setOutlineThickness(OUTLINE_THICKNESS);
    shape.setOutlineColor(Color(BACKGROUND_COLOR).toSFMLColor());

    const sf::Vector2i mousePos = sf::Mouse::getPosition(renderWindow) - sf::Vector2i(offset / 2.0f);

    for (unsigned int row=0; row < map.getHeight(); row++) {
        for (unsigned int col=0; col < map.getWidth(); col++) {
            sf::Vector2f shapePos(
                    cellSize * static_cast<float>(col),
                    cellSize * static_cast<float>(row)
                    );

            shape.setPosition(shapePos + offset / 2.0f);

            MapElem particle = map.getParticle(Position(row, col));

            const Color& color = (particle == nullptr) ? Color(BACKGROUND_COLOR) : particle->getColor();

            shape.setFillColor(color.toSFMLColor());

            renderWindow.draw(shape);

            if (mousePos.x >= shapePos.x && mousePos.x < shapePos.x + cellSize
                && mousePos.y >= shapePos.y && mousePos.y < shapePos.y + cellSize) {
                shape.setFillColor(Color(255, 255, 0, 63).toSFMLColor());
                renderWindow.draw(shape);
            }
        }
    }

    sf::RectangleShape border(sf::Vector2f(
            cellSize * static_cast<float>(map.getWidth()),
            cellSize * static_cast<float>(map.getHeight())
            ));

    border.move(offset / 2.0f);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(1);
    border.setOutlineColor(sf::Color::White);

    renderWindow.draw(border);

    renderWindow.display();
}

void Window::exit() {
    renderWindow.close();
}

void Window::handleInput(Map& map, const sf::Event::KeyEvent& key, bool pressed) {
    switch (key.code) {
        case sf::Keyboard::F4:
            if (key.alt) {
                exit();
            }
            break;

        case sf::Keyboard::Escape:
            exit();
            break;

        default:
            break;
    }
}

void Window::handleMouse(Map& map, const sf::Event::MouseButtonEvent& mouse, bool pressed) {
    const float cellSize = std::min(
            static_cast<float>(renderWindow.getSize().x) / static_cast<float>(map.getWidth()),
            static_cast<float>(renderWindow.getSize().y) / static_cast<float>(map.getHeight())
    );

    const sf::Vector2f offset = sf::Vector2f(renderWindow.getSize()) - sf::Vector2f(
            static_cast<float>(map.getWidth()) * cellSize,
            static_cast<float>(map.getHeight()) * cellSize
    );

    const sf::Vector2i mousePos = sf::Mouse::getPosition(renderWindow) - sf::Vector2i(offset / 2.0f);

    if (mousePos.x >= 0 && mousePos.x < map.getWidth()*cellSize &&
        mousePos.y >= 0 && mousePos.y < map.getHeight()*cellSize) {

        Position p(
                mousePos.y / cellSize,
                mousePos.x / cellSize
                );

        if (pressed) {
            if (mouse.button == sf::Mouse::Left) {
                if (map.isValidPosition(p)) {
                    map.setParticle(MapElem(new SandParticle()), p);
                } else {
                    std::cerr << p.first << ' ' << p.second << '\n';
                }
            }
            else if (mouse.button == sf::Mouse::Right) {
                if (map.isValidPosition(p)) {
                    map.removeParticle(p);
                } else {
                    std::cerr << p.first << ' ' << p.second << '\n';
                }
            }
        }
    }
}

void Window::handleResize(const Map& map, sf::Event::SizeEvent& size) {
    const float cellWidth = (float) size.width / (float) map.getWidth();
    const float cellHeight = (float) size.height / (float) map.getHeight();

    /*
    if (cellWidth > 2*OUTLINE_THICKNESS + 1 && cellHeight > 2 * OUTLINE_THICKNESS + 1) {
        // renderWindow.setSize(sf::Vector2u(size.width, size.height));
        // TODO : OK
    }
    else {
        // renderWindow.setSize(sf::Vector2u(1000, 1000));
        // TODO : NOK
    }
     */

    renderWindow.setView(sf::View(sf::FloatRect(0, 0, size.width, size.height)));
}

bool Window::isRunning() const {
    return renderWindow.isOpen();
}
