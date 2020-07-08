// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Observable
 */
// Created by Romain on 05/05/2020.

#ifndef MAZE_OBSERVABLE_H
#define MAZE_OBSERVABLE_H

#include <map>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#include "Observer.fwd.h"
#include "Observable.fwd.h"

/**
 * Classe Observable
 */
class Observable {
public:
    /**
     * Ajoute un observer
     *
     * @param obs Pointeur vers l'observer
     */
    void addObserver(Observer* obs);

    /**
     * Retire un observer
     *
     * @param obs Pointeur vers l'observer
     */
    void deleteObserver(Observer* obs);

    /**
     * Retire tous les observers
     */
    void deleteObservers();

    /**
     * Notifie les observers
     */
    void notifyObservers();

    /**
     * Notifie les observers avec un message
     *
     * @param msg Message
     */
    void notifyObservers(const std::string msg);

    /**
     * Si l'observable a changé ou non
     *
     * @return Changé
     */
    [[nodiscard]] bool hasChanged() const;

    /**
     * Compte les observers
     *
     * @return Nombre d'observers
     */
    [[nodiscard]] int countObservers() const;

protected:
    /**
     * Marque comme changé
     */
    void setChanged();

    /**
     * Marque comme inchangé
     */
    void clearChanged();

private:
    /**
     * Changé ou non
     */
    bool changed;

    /**
     * Observers
     */
    std::map<Observer*, Observer*> observers;
};

#endif //MAZE_OBSERVABLE_H