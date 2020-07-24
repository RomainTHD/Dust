// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Vue générique
 */
// Created by Romain on 24/07/2020.

#ifndef DUST_GENERICVIEW_H
#define DUST_GENERICVIEW_H

#include "game/Map.h"

/**
 * Vue générique pour un affichage console ou fenêtre
 */
class GenericView {
public:
    /**
     * Destructeur virtuel pour être override
     */
    virtual ~GenericView() = default;

    /**
     * Si la vue tourne encore ou non
     *
     * @return Running ou non
     */
    [[nodiscard]] virtual bool isRunning() const = 0;

    /**
     * Gestion des évènements
     *
     * @param map Map
     */
    virtual void processEvents(const Map& map) {};

    /**
     * Affichage
     *
     * @param map Map
     */
    virtual void render(const Map& map) = 0;
};

#endif //DUST_GENERICVIEW_H
