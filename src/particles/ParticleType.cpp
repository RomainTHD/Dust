// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 06/07/2020.

#include "particles/ParticleType.h"

ParticleType::ParticleType(Value val) :
    value(val)
    {}

ParticleType::operator Value() const {
    return value;
}

bool ParticleType::operator==(ParticleType other) const {
    return value == other.value;
}

bool ParticleType::operator==(ParticleType::Value v) const {
    return value == v;
}

bool ParticleType::operator!=(ParticleType other) const {
    return value != other.value;
}

bool ParticleType::operator!=(ParticleType::Value v) const {
    return value != v;
}
