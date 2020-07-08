// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "particles/Particle.h"

Particle::Particle(ParticleType t, Color color) :
    stateChanged(true),
    color(color),
    type(t)
    {}

bool Particle::hasChanged() {
    return stateChanged;
}

Color Particle::getColor() {
    return color;
}

void Particle::setChanged() {
    stateChanged = true;
}

void Particle::clearChanged() {
    stateChanged = false;
}
