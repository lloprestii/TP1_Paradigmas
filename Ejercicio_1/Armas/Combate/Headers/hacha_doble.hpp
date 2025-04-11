#include "ArmaCombate.hpp"

class HachaDoble : public ArmaCombate {
    public:
        // Constructor
        HachaDoble(string nombre, int dano_base, int durabilidad);

        // Implementación de los métodos virtuales
        string get_nombre() override { return ArmaCombate::get_nombre(); }
        int get_dano_base() override { return ArmaCombate::get_dano_base(); }
        int get_durabilidad() override { return ArmaCombate::get_durabilidad(); }
        int get_velocidad_ataque() override { return ArmaCombate::get_velocidad_ataque(); }
        int get_precision() override { return ArmaCombate::get_precision(); }
        int get_probabilidad_critico() override { return ArmaCombate::get_probabilidad_critico(); }
        void set_durabilidad(int nueva_durabilidad) override { ArmaCombate::set_durabilidad(nueva_durabilidad); }
        void mostrar_info() override { ArmaCombate::mostrar_info(); }
};