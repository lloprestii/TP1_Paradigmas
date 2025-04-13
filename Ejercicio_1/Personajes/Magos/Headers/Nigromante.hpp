#pragma once
#include "Magos.hpp"

class Nigromante : public Magos {
    public:
        Nigromante(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};