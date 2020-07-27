// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Type de particule
 */
// Created by Romain on 06/07/2020.

#ifndef DUST_PARTICLETYPE_H
#define DUST_PARTICLETYPE_H

#include <cstdint>

/**
 * Type de particule
 */
class ParticleType {
public:
    /**
     * Énum des différentes valeurs
     */
    enum Value : uint8_t {
        SAND
    };

    /**
     * Constructeur
     */
    ParticleType() = default;

    /**
     * Constructeur<br>
     * Non explicit car sinon <code>ParticleType t = ParticleType::SAND;</code> ne fonctionne pas
     * @param val Valeur
     */
    ParticleType(Value val);

    /**
     * ̈Permet d'utiliser une instance de ParticleType dans un switch<br>
     * Non explicit car sinon casse le switch
     * @return Valeur
     */
    operator Value() const;

    /**
     * Évite l'utilisation <code>if (t)</code>
     */
    explicit operator bool() = delete;

    /**
     * <code>p1 == p2</code>
     * @param other Autre type de particule
     * @return Égal ou non
     */
    bool operator==(ParticleType other) const;

    /**
     * <code>p == ParticleType::SAND</code>
     * @param v Valeur
     * @return Égal ou non
     */
    bool operator==(Value v) const;

    /**
     * <code>p1 != p2</code>
     * @param other Autre type de particule
     * @return Égal ou non
     */
    bool operator!=(ParticleType other) const;

    /**
     * <code>p != ParticleType::SAND</code>
     * @param v Valeur
     * @return Égal ou non
     */
    bool operator!=(Value v) const;
private:
    Value value;
};

#endif //DUST_PARTICLETYPE_H
