// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 05/05/2020.

#include "util/Observable.h"
#include "util/Observer.h"

void Observable::addObserver(Observer *obs)  {
    if (obs == nullptr) {
        throw std::invalid_argument("Observer null");
    }

    if (observers.find(obs) == observers.end()) {
        observers.emplace(obs, obs);
    }
    else {
        // throw std::invalid_argument("Observer déjà présent");
        std::cerr << "Observer déjà présent" << std::endl;
    }
}

void Observable::deleteObserver(Observer *obs) {
    observers.erase(obs);
}

void Observable::deleteObservers() {
    observers.clear();
}

void Observable::notifyObservers() {
    notifyObservers("");
}

void Observable::notifyObservers(const std::string msg) {
    std::map<Observer*, Observer*> buffer(observers);

    for (auto const& iter : buffer) {
        Observer *value = iter.second;

        value->update(this, msg);
    }

    clearChanged();
}

bool Observable::hasChanged() const {
    return changed;
}

int Observable::countObservers() const {
    return observers.size();
}

void Observable::setChanged() {
    changed = true;
}

void Observable::clearChanged() {
    changed = false;
}
