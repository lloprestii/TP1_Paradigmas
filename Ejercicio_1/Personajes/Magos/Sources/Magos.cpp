#include "../Headers/Magos.hpp"
#include <iostream>

using namespace std;

Magos::Magos(string nombre, int vida, int mana, int armadura, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas) :
    nombre(nombre),
    vida(vida),
    mana(mana),
    armadura(armadura),
    armas(armas)
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

void Magos::recibir_dano(int dano) {
    int dano_final = dano - armadura;
    if (dano_final < 0) dano_final = 0;
    
    vida -= dano_final;
    if (vida < 0) vida = 0;
    
    cout << nombre << " recibe " << dano_final << " puntos de daño." << endl;
}

bool Magos::esta_vivo() const {
    return vida > 0;
}

void Magos::atacar(shared_ptr<Personaje> atacante, shared_ptr<Personaje> objetivo) {
    if (!esta_vivo()) {
        cout << nombre << " no puede atacar porque esta muerto." << endl;
        return;
    }
    
    if (!objetivo) {
        cout << "No hay objetivo para atacar." << endl;
        return;
    }

    if (rand() % 100 < atacante->get_armas().first->get_precision()) {
        int dano_base = atacante->get_armas().first->get_dano_base();
        
        if (rand() % 100 < atacante->get_armas().first->get_probabilidad_critico()) {
            dano_base *= 2;
            cout << atacante->get_nombre() << " realiza un ataque critico!" << endl;
        }
        
        cout << atacante->get_nombre() << " lanza un ataque con " << dano_base << " puntos de daño." << endl;
        objetivo->recibir_dano(dano_base);
    } else {
        cout << atacante->get_nombre() << " falla el ataque!" << endl;
    }
}

pair<shared_ptr<Arma>, shared_ptr<Arma>> Magos::get_armas() const {
    return armas;
}

void Magos::set_armas(pair<shared_ptr<Arma>, shared_ptr<Arma>> nuevas_armas) {
    armas = nuevas_armas;
}
