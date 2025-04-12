#pragma once

#include "../../Personaje.hpp"
#include "../../../Armas/Arma.hpp"
#include <memory>

class Guerrero : public Personaje {
    private:
        string nombre;
        int vida;
        int fuerza;
        int armadura;
        shared_ptr<Arma> arma;

    public:
        Guerrero(string nombre, int vida, int fuerza, int armadura, shared_ptr<Arma> arma);
        virtual ~Guerrero() = default;

        int get_vida() const override;
        void set_vida(int nueva_vida) override;
        string get_nombre() const override;
        void set_nombre(string nuevo_nombre) override;
        void recibir_dano(int dano, bool es_dano_magico = false) override;
        bool esta_vivo() const override;
        void atacar(Personaje* atacante, Personaje* objetivo) override;
        virtual void mostrar_info() const override = 0;
        shared_ptr<Arma> get_arma() const;
        void set_arma(shared_ptr<Arma> nueva_arma) override;
};
        