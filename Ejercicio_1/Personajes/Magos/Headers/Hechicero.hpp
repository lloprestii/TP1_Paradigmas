#pragma once
#include "Magos.hpp"

class Hechicero : public Magos {
    public:
        Hechicero(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};