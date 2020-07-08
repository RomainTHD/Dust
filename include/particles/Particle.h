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
#include "view/Color.h"

/**
 * Particule
 */
class Particle {
public:
    /**
     * Constructeur
     * @param type Type de particule
     * @param color Couleur de la particule
     */
    Particle(ParticleType type, Color color);

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
     * Getter de la couleur
     * @return Couleur
     */
    [[nodiscard]] Color getColor();

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

    /**
     * Couleur de la particule
     */
    Color color;
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
