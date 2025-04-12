#pragma once
#include <string>

using namespace std;

class Personaje;

class Arma {
    public:
        virtual string get_nombre() const = 0;
        virtual int get_dano_base() const = 0;
        virtual int get_durabilidad() const = 0;
        virtual int get_velocidad_ataque() const = 0;
        virtual int get_precision() const = 0;
        virtual int get_probabilidad_critico() const = 0;
        virtual bool get_esta_destruida() const = 0;
        virtual void set_durabilidad(int nueva_durabilidad) = 0;
        virtual void mostrar_info() = 0;
        virtual void atacar() const = 0;
        virtual ~Arma() = default;
};


