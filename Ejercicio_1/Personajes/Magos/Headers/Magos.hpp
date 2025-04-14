#pragma once
#include "../../Personaje.hpp"
#include "../../../Armas/Magicas/Headers/ArmaMagica.hpp"
#include <memory>

using namespace std;

class Magos : public Personaje {
    protected:
        string nombre;
        int vida;
        int mana;
        int armadura;
        pair<shared_ptr<Arma>, shared_ptr<Arma>> armas;

    public:
        Magos(string nombre, int vida, int mana, int armadura, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        virtual ~Magos() = default;

        int get_vida() const override;
        void set_vida(int nueva_vida) override;
        string get_nombre() const override;
        void set_nombre(string nuevo_nombre) override;
        pair<shared_ptr<Arma>, shared_ptr<Arma>> get_armas() const override;
        void set_armas(pair<shared_ptr<Arma>, shared_ptr<Arma>> nuevas_armas) override;
        void recibir_dano(int dano) override;
        bool esta_vivo() const override;
        void atacar(shared_ptr<Personaje> atacante, shared_ptr<Personaje> objetivo) override;
        void set_armadura(int nueva_armadura) override;
        void mostrar_info() const override = 0;
};

        

