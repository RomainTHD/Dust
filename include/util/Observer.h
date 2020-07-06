// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Observer observant un Observable
 */
// Created by Romain on 05/05/2020.

#ifndef MAZE_OBSERVER_H
#define MAZE_OBSERVER_H

#include "Observer.fwd.h"
#include "Observable.fwd.h"

#include <string>
#include <iostream>

/**
 * Objet observant un Observable
 */
class Observer {
public:
    /**
     * Mise à jour de l'observer
     *
     * @param obs Observable
     * @param msg Message
     */
    virtual void update(Observable* obs, std::string msg) = 0;
};

#endif //MAZE_OBSERVER_H
