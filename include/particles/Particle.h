// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Particule
 */
// Created by Romain on 06/07/2020.

#ifndef DUST_PARTICLE_H
#define DUST_PARTICLE_H

#include "Particle.fwd.h"
#include "map/Map.fwd.h"
#include "ParticleType.h"

/**
 * Particule
 */
class Particle {
public:
    /**
     * Constructeur<br>
     * Type = NOT_INITIALIZED
     */
    Particle();

    /**
     * Constructeur
     * @param type Type de particule
     */
    explicit Particle(ParticleType type);

    /**
     * Destructeur
     */
    ~Particle() = default;

    /**
     * Si la particule a changé ou non pendant son update
     * @return Changée ou non
     */
    [[nodiscard]] bool hasChanged();

    /**
     * Méthode à exécuter lors de l'update
     */
    virtual void update() = 0;

protected:
    /**
     * Marque la particule comme modifiée
     */
    void setChanged();

    /**
     * Marque la particule comme non-modifiée
     */
    void clearChanged();

private:
    /**
     * Particule modifiée ou non
     */
    bool stateChanged;

    /**
     * Type de particule
     */
    ParticleType type;
};


#endif //DUST_PARTICLE_H
