#pragma once

#include "Guerreros.hpp"
#include <string>

class Barbaro : public Guerrero {
    public:
        Barbaro(string nombre);
        virtual ~Barbaro() = default;
        
        // Métodos heredados de Personaje
        int get_vida() override;
        void set_vida(int nueva_vida) override;
        string get_nombre() override;
        void set_nombre(string nuevo_nombre) override;
        void recibir_dano(int dano) override;
        bool esta_vivo() override;
        void atacar(Personaje* objetivo) override;
        void mostrar_info() override;
};

