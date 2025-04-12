#pragma once

#include "../../Personaje.hpp"
#include "../../../Armas/Arma.hpp"
#include <memory>

class Guerrero : public Personaje {
    private:
        string nombre;
        int vida;
        int resistencia_fisica;
        int resistencia_magica;
        int armadura;
        int fuerza;
        shared_ptr<Arma> arma;

    public:
        Guerrero(string nombre, int vida, int resistencia_fisica, int resistencia_magica, int armadura, int fuerza, shared_ptr<Arma> arma);
        virtual ~Guerrero() = default;

        virtual int get_vida() const override;
        virtual void set_vida(int nueva_vida) override;
        virtual string get_nombre() const override;
        virtual void set_nombre(string nuevo_nombre) override;
        virtual void recibir_dano(int dano, bool es_dano_magico = false) override;
        virtual bool esta_vivo() const override;
        virtual void atacar(Personaje* objetivo) override;
        virtual void mostrar_info() const override;

        
        // Metodos específicos de Guerrero
        virtual int get_resistencia_fisica() const;
        virtual void set_resistencia_fisica(int nueva_resistencia);
        virtual int get_resistencia_magica() const;
        virtual void set_resistencia_magica(int nueva_resistencia);
        virtual int get_armadura() const;
        virtual void set_armadura(int nueva_armadura);
        virtual int get_fuerza() const;
        virtual void set_fuerza(int nueva_fuerza);
        virtual shared_ptr<Arma> get_arma() const;
        virtual void set_arma(shared_ptr<Arma> nueva_arma);
};
        