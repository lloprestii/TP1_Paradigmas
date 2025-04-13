#pragma once
#include "Magos.hpp"

class Conjurador : public Magos {
    public:
        Conjurador(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};