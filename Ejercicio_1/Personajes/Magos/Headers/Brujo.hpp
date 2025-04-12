#pragma once
#include "Magos.hpp"

class Brujo : public Magos {
    public:
        Brujo(string nombre);
        void mostrar_info() const override;
};