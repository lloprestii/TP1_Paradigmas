#pragma once
#include "Magos.hpp"

class Conjurador : public Magos {
    public:
        Conjurador(string nombre);
        void mostrar_info() const override;
};