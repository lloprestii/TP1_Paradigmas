#pragma once
#include <string>

using namespace std;

class Personaje;

class Arma {
    protected:
        string nombre;
        int dano_base;
        int durabilidad;
        int velocidad_ataque;
        int precision;
        int probabilidad_critico;
        bool esta_destruida;
    public:
        Arma() = default;
        virtual ~Arma() = default;
        
        // Getters
        virtual string get_nombre() const = 0;
        virtual int get_dano_base() const = 0;
        virtual int get_durabilidad() const = 0;
        virtual int get_velocidad_ataque() const = 0;
        virtual int get_precision() const = 0;
        virtual int get_probabilidad_critico() const = 0;
        virtual bool get_esta_destruida() const = 0;
        
        // Setters
        virtual void set_durabilidad(int nueva_durabilidad) = 0;
        
        // Métodos
        virtual void mostrar_info() = 0;
        virtual void usar(Personaje* atacante, Personaje* objetivo) = 0;
};


