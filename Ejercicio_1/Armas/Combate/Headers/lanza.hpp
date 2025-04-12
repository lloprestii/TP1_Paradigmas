#pragma once
#include "ArmaCombate.hpp"

class Lanza : public ArmaCombate {
    public:
        Lanza(string nombre, int dano_base, int durabilidad);
        void atacar() const override;
};