#pragma once

#include <iostream>
#include <string>

using namespace std;

class Personaje {
    public: 
        // Getters y Setters básicos
        virtual int get_vida() const = 0;
        virtual void set_vida(int nueva_vida) = 0;
        virtual string get_nombre() const = 0;
        virtual void set_nombre(string nuevo_nombre) = 0;

        // Métodos de combate
        virtual void recibir_dano(int dano, bool es_dano_magico = false) = 0;
        virtual bool esta_vivo() const = 0;
        virtual void atacar(Personaje* objetivo) = 0;

        // Método de información
        virtual void mostrar_info() const = 0;

        // Destructor virtual
        virtual ~Personaje() = default;

    protected:
        // Constructor protegido para evitar instanciación directa
        Personaje() = default;
};

