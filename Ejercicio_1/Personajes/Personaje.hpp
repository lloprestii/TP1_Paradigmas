#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "../Armas/Arma.hpp"

using namespace std;

class Personaje {
    public: 
        virtual int get_vida() const = 0;
        virtual void set_vida(int nueva_vida) = 0;
        virtual string get_nombre() const = 0;
        virtual void set_nombre(string nuevo_nombre) = 0;
        virtual pair<shared_ptr<Arma>, shared_ptr<Arma>> get_armas() const = 0;
        virtual void set_armas(pair<shared_ptr<Arma>, shared_ptr<Arma>> nuevas_armas) = 0;

        virtual void recibir_dano(int dano) = 0;
        virtual bool esta_vivo() const = 0;
        virtual void atacar(shared_ptr<Personaje> atacante, shared_ptr<Personaje> objetivo) = 0;

        virtual void mostrar_info() const = 0;

        virtual ~Personaje() = default;
};

