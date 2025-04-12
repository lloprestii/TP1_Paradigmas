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
        int dano_magico;
        int mana_requerido;
        int probabilidad_critico;
        bool esta_destruida;
        int poder_curacion;

    public:
        ArmaMagica(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int dano_magico, int mana_requerido, int probabilidad_critico, bool esta_destruida, int poder_curacion = 20);

        ~ArmaMagica() = default;

        string get_nombre() const override;
        int get_dano_base() const override;
        int get_durabilidad() const override;
        int get_velocidad_ataque() const override;
        int get_precision() const override;
        int get_probabilidad_critico() const override;
        bool get_esta_destruida() const override;
        
        int get_dano_magico() const;
        int get_mana_requerido() const;
        int get_poder_curacion() const;

        void set_durabilidad(int nueva_durabilidad) override;
        void set_dano_magico(int dano_magico);
        void set_mana_requerido(int mana_requerido);
        void set_poder_curacion(int poder_curacion);

        void mostrar_info() override;
        void mostrar_estado();

        virtual void atacar() const override = 0;
};
