// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "particles/Particle.h"

Particle::Particle(ParticleType t, Color color) :
    color(color),
    stateChanged(true),
    type(t)
    {}

bool Particle::hasChanged() const {
    return stateChanged;
}

Color& Particle::getColor() {
    return color;
}

void Particle::setChanged() {
    stateChanged = true;
}

void Particle::clearChanged() {
    stateChanged = false;
}
