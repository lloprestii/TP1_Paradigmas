#pragma once
#include "Magos.hpp"

class Brujo : public Magos {
    public:
        Brujo(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};