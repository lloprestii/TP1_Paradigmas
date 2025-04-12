#pragma once
#include "ArmaCombate.hpp"

class Espada : public ArmaCombate{
    public:
        Espada(const string& nombre, int dano_base, int durabilidad); 
        void atacar() const override;
};



