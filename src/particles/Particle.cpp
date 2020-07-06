// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "particles/Particle.h"

Particle::Particle() :
        Particle(ParticleType::NOT_INITIALIZED)
{}

Particle::Particle(ParticleType t) :
    stateChanged(true),
    type(t)
    {}

bool Particle::hasChanged() {
    return stateChanged;
}

void Particle::setChanged() {
    stateChanged = true;
}

void Particle::clearChanged() {
    stateChanged = false;
}
