#pragma once
#include "../../Arma.hpp"
#include <string>
#include <random>

using namespace std;

class ArmaMagica : public Arma {
    private:
        string nombre;
        int dano_base;
        int durabilidad;
        int velocidad_ataque;
        int precision;
        int probabilidad_critico;
        
    public:
        // Constructor protegido
        ArmaMagica(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int probabilidad_critico);
        virtual ~ArmaMagica() = default;

        // Getters y Setters
        string get_nombre() const override;
        int get_dano_base() const override;
        int get_durabilidad() const override;
        int get_velocidad_ataque() const override;
        int get_precision() const override;
        int get_probabilidad_critico() const override;
        bool get_esta_destruida() const override;
        void set_durabilidad(int nueva_durabilidad) override;

        // Métodos de información
        void mostrar_info() const override;

        // Método virtual puro
        virtual void atacar() const override = 0;
};
