#pragma once
#include "ArmaCombate.hpp"

class Garrote : public ArmaCombate {
    public:
        Garrote(string nombre, int dano_base, int durabilidad);

        // Implementación de los métodos virtuales
        string get_nombre() override { return ArmaCombate::get_nombre(); }
        int get_dano_base() override { return ArmaCombate::get_dano_base(); }
        int get_durabilidad() override { return ArmaCombate::get_durabilidad(); }
        int get_velocidad_ataque() override { return ArmaCombate::get_velocidad_ataque(); }
        int get_precision() override { return ArmaCombate::get_precision(); }
        int get_probabilidad_critico() override { return ArmaCombate::get_probabilidad_critico(); }
        bool get_esta_destruida() override { return ArmaCombate::get_esta_destruida(); }
        void set_durabilidad(int nueva_durabilidad) override { ArmaCombate::set_durabilidad(nueva_durabilidad); }
        void mostrar_info() override { ArmaCombate::mostrar_info(); }
};
