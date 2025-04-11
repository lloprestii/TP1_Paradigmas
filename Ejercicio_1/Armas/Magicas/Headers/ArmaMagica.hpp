#pragma once
#include <string>
#include "../../Arma.hpp"

using namespace std;

class ArmaMagica : public Arma {
    private:
        string nombre;
        int dano_base;
        int durabilidad;
        int velocidad_ataque;
        int precision;
        int mana_requerido;
        string elemento_magico;
        int poder_magico;
        bool encantada;
        int curacion;
        bool esta_destruida;

    public:
        ArmaMagica(string nombre, int dano_base, int durabilidad, int velocidad_ataque, 
                  int precision, int mana_requerido, const string& elemento_magico, 
                  int poder_magico, bool encantada, int curacion, bool esta_destruida);

        ~ArmaMagica() override = default;

        // Getters
        int get_mana_requerido() const;
        string get_elemento_magico() const;
        int get_poder_magico() const;
        bool get_encantada() const;
        int get_curacion() const;
        bool get_esta_destruida() const;

        // Setters
        void set_mana_requerido(int mana);
        void set_elemento_magico(string elemento);
        void set_poder_magico(int poder);
        void set_encantada(bool encantada);
        void set_curacion(int curacion);

        // Metodos propios de la clase
        void encantar();
        void lanzar_hechizo();
        void recargar_mana();
        void cambiar_elemento(string nuevo_elemento);
        void aumentar_poder_magico(int cantidad);

        // Metodos heredados de Arma
        void mostrar_info() override;
        string get_nombre() override;
        int get_dano_base() override;
        int get_durabilidad() override;
        int get_velocidad_ataque() override;
        int get_precision() override;
};
