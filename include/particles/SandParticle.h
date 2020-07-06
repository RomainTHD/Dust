// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Particule de sable
 */
// Created by Romain on 06/07/2020.

#ifndef DUST_SANDPARTICLE_H
#define DUST_SANDPARTICLE_H

#include "particles/Particle.h"

/**
 * Particule de sable
 */
class SandParticle : Particle {
public:
    SandParticle();

    void update() override {};
};

#endif //DUST_SANDPARTICLE_H
