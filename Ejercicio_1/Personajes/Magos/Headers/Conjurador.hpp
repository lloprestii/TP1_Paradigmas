#pragma once
#include "Magos.hpp"

class Conjurador : public Magos {
    public:
        Conjurador(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};