#pragma once
#include "../../Personaje.hpp"
#include "../../../Armas/Arma.hpp"
#include <memory>

class Magos : public Personaje{
    private:
        string nombre;
        int vida;
        int energia;
        int resistencia_fisica;
        int resistencia_magica;
        int armadura;
        int mana;
        shared_ptr<Arma> arma;

    public:
        Magos(string nombre, int vida, int energia, int resistencia_fisica, int resistencia_magica, int armadura, int mana, shared_ptr<Arma> arma);
        virtual ~Magos() = default;

        // Metodos heredados de Personaje
        virtual int get_vida() const override;
        virtual void set_vida(int nueva_vida) override;
        virtual string get_nombre() const override;
        virtual void set_nombre(string nuevo_nombre) override;
        virtual void recibir_dano(int dano, bool es_dano_magico = false) override;
        virtual bool esta_vivo() const override;
        virtual void atacar(Personaje* objetivo) override;
        virtual void mostrar_info() const override;

        virtual int get_resistencia_fisica() const;
        virtual void set_resistencia_fisica(int nueva_resistencia);
        virtual int get_resistencia_magica() const;
        virtual void set_resistencia_magica(int nueva_resistencia);
        virtual int get_armadura() const;
        virtual void set_armadura(int nueva_armadura);
        virtual int get_mana() const;
        virtual void set_mana(int nueva_mana);
        virtual shared_ptr<Arma> get_arma() const;
        virtual void set_arma(shared_ptr<Arma> nueva_arma);
        virtual void lanzar_hechizo();
        virtual void recargar_mana();
        virtual void mostrar_estado() const;
        virtual void regenerar_mana();
        virtual void meditar();
        virtual void recibir_curacion(int cantidad);
};

        

