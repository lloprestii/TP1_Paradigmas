#pragma once
#include "../../Arma.hpp"
#include <string>

using namespace std;

class Personaje;

class ArmaCombate : public Arma {
    private:
        // Atributos
        string nombre;
        int dano_base;
        int durabilidad;
        int velocidad_ataque;
        int precision;
        int alcance;
        int dano_cortante;
        bool es_doble_mano;
        int probabilidad_critico;
        int costo_energia;
        bool esta_destruida;
        
    public:
        ArmaCombate(const string& nombre, int dano_base, int durabilidad, 
                    int velocidad_ataque, int precision, int alcance, int dano_cortante, 
                    bool es_doble_mano, int probabilidad_critico, int costo_energia);

        ~ArmaCombate() = default;

        // Getters
        int get_alcance() const;
        int get_dano_cortante() const;
        bool get_es_doble_mano() const;
        int get_probabilidad_critico() const;
        int get_costo_energia() const;
        bool get_esta_destruida() const;

        // Setters
        void set_alcance(int alcance);
        void set_dano_cortante(int dano_cortante);
        void set_es_doble_mano(bool es_doble_mano);
        void set_probabilidad_critico(int probabilidad_critico);
        void set_costo_energia(int costo_energia);
        void set_esta_destruida(bool esta_destruida);
        void set_durabilidad(int nueva_durabilidad) override;

        // Métodos heredados de Arma
        string get_nombre() override;
        int get_dano_base() override;
        int get_durabilidad() override;
        int get_velocidad_ataque() override;
        int get_precision() override;
        void mostrar_info() override;

        // Métodos propios de la clase
        void bloquear();
        void afilar();
        void mostrar_estado();
        bool lanzar_arma();
        void reparar();
};






