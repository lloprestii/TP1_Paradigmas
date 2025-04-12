#include "../Headers/Magos.hpp"
#include <iostream>

using namespace std;

Magos::Magos(string nombre, int vida, int mana, int armadura, shared_ptr<Arma> arma) :
    nombre(nombre),
    vida(vida),
    mana(mana),
    armadura(armadura),
    arma(arma)
{}

int Magos::get_vida() const {
    return vida;
}

void Magos::set_vida(int nueva_vida) {
    vida = nueva_vida;
}

string Magos::get_nombre() const {
    return nombre;
}

void Magos::set_nombre(string nuevo_nombre) {
    nombre = nuevo_nombre;
}

void Magos::recibir_dano(int dano, bool es_dano_magico) {
    int dano_final = dano - armadura;
    if (dano_final < 0) dano_final = 0;
    
    vida -= dano_final;
    if (vida < 0) vida = 0;
    
    cout << nombre << " recibe " << dano_final << " puntos de daño." << endl;
}

bool Magos::esta_vivo() const {
    return vida > 0;
}

void Magos::atacar(Personaje* atacante, Personaje* objetivo) {
    if (!esta_vivo()) {
        cout << nombre << " no puede atacar porque esta muerto." << endl;
        return;
    }
    
    if (!objetivo) {
        cout << "No hay objetivo para atacar." << endl;
        return;
    }

    if (rand() % 100 < atacante->get_arma()->get_precision()) {
        int dano_base = atacante->get_arma()->get_dano_base();
        
        if (rand() % 100 < atacante->get_arma()->get_probabilidad_critico()) {
            dano_base *= 2;
            cout << atacante->get_nombre() << " realiza un ataque critico!" << endl;
        }
        
        cout << atacante->get_nombre() << " lanza un ataque con " << dano_base << " puntos de daño." << endl;
        objetivo->recibir_dano(dano_base, true);
    } else {
        cout << atacante->get_nombre() << " falla el ataque!" << endl;
    }
}

shared_ptr<Arma> Magos::get_arma() const {
    return arma;
}

void Magos::set_arma(shared_ptr<Arma> nueva_arma) {
    arma = nueva_arma;
}