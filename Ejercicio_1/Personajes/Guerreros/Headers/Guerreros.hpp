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
        pair<unique_ptr<Arma>, unique_ptr<Arma>> armas;

    public:
        Guerrero(string nombre, int vida, int fuerza, int armadura, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        virtual ~Guerrero() = default;
        int get_vida() const override;
        void set_vida(int nueva_vida) override;
        string get_nombre() const override;
        void set_nombre(string nuevo_nombre) override;
        const pair<unique_ptr<Arma>, unique_ptr<Arma>>& get_armas() const override;
        void set_armas(pair<unique_ptr<Arma>, unique_ptr<Arma>> nuevas_armas) override;
        void set_armadura(int nueva_armadura) override;
        void recibir_dano(int dano) override;
        bool esta_vivo() const override;
        void atacar(Personaje& atacante, Personaje& objetivo) override;
        void mostrar_info() const override = 0;
};
        