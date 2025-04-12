#pragma once

#include "../../Personaje.hpp"
#include "../../../Armas/Combate/Headers/ArmaCombate.hpp"
#include <memory>

using namespace std;

class Guerrero : public Personaje {
    protected:
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
        shared_ptr<Arma> get_arma() const override;
        void set_arma(shared_ptr<Arma> nueva_arma) override;
        void recibir_dano(int dano) override;
        bool esta_vivo() const override;
        void atacar(shared_ptr<Personaje> atacante, shared_ptr<Personaje> objetivo) override;
        void mostrar_info() const override = 0;
};
        