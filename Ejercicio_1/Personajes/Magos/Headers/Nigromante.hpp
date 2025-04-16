#pragma once
#include "Magos.hpp"

class Nigromante : public Magos {
    public:
        Nigromante(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};