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
                    bool es_doble_mano, int probabilidad_critico, int costo_energia, bool esta_destruida);

        ~ArmaCombate() = default;

        // Getters
        string get_nombre() const override;
        int get_dano_base() const override;
        int get_durabilidad() const override;
        int get_velocidad_ataque() const override;
        int get_precision() const override;
        int get_probabilidad_critico() const override;
        bool get_esta_destruida() const override;
        
        // Getters adicionales
        int get_alcance() const;
        int get_dano_cortante() const;
        bool get_es_doble_mano() const;
        int get_costo_energia() const;

        // Setters
        void set_alcance(int alcance);
        void set_dano_cortante(int dano_cortante);
        void set_es_doble_mano(bool es_doble_mano);
        void set_probabilidad_critico(int probabilidad_critico);
        void set_costo_energia(int costo_energia);
        void set_durabilidad(int nueva_durabilidad) override;

        // Métodos heredados de Arma
        void mostrar_info() override;

        // Métodos propios de la clase
        void bloquear();
        void afilar();
        void mostrar_estado();
        bool lanzar_arma();
        void reparar();
};






