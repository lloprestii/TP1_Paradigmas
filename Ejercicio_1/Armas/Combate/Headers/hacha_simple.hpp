#pragma once
#include "ArmaCombate.hpp"

class HachaSimple : public ArmaCombate {
    public:
        HachaSimple(string nombre, int dano_base, int durabilidad);
        void atacar() const override;
};