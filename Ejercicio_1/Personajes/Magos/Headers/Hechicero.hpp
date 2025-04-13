#pragma once
#include "Magos.hpp"

class Hechicero : public Magos {
    public:
        Hechicero(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};