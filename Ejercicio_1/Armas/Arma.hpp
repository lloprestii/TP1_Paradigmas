#pragma once
#include <string>

using namespace std;

class Personaje;

class Arma {
    public:
        // Getters y Setters básicos
        virtual string get_nombre() const = 0;
        virtual int get_dano_base() const = 0;
        virtual int get_durabilidad() const = 0;
        virtual void set_durabilidad(int nueva_durabilidad) = 0;

        // Atributos de combate
        virtual int get_velocidad_ataque() const = 0;
        virtual int get_precision() const = 0;
        virtual int get_probabilidad_critico() const = 0;
        virtual bool get_esta_destruida() const = 0;

        // Métodos de información y uso
        virtual void mostrar_info() const = 0;
        virtual void atacar() const = 0;

        // Destructor virtual
        virtual ~Arma() = default;

    protected:
        // Constructor protegido para evitar instanciación directa
        Arma() = default;
};


