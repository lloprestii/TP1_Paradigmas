#pragma once
#include "Magos.hpp"

class Brujo : public Magos {
    public:
        Brujo(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};