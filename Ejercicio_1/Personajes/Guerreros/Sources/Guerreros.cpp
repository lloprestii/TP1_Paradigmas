#include "../Headers/Guerreros.hpp"
#include <iostream>

using namespace std;

Guerrero::Guerrero(string nombre, int vida, int fuerza, int armadura, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas) :
    nombre(nombre),
    vida(vida),
    fuerza(fuerza),
    armadura(armadura),
    armas(armas)
{}

int Guerrero::get_vida() const {
    return vida;
}

void Guerrero::set_vida(int nueva_vida) {
    vida = nueva_vida;
}

string Guerrero::get_nombre() const {
    return nombre;
}

void Guerrero::set_nombre(string nuevo_nombre) {
    nombre = nuevo_nombre;
}

void Guerrero::recibir_dano(int dano) {
    int dano_final = dano - armadura;
    if (dano_final < 0) dano_final = 0;
    
    vida -= dano_final;
    if (vida < 0) vida = 0;
    
    cout << nombre << " recibe " << dano_final << " puntos de daño." << endl;
}

bool Guerrero::esta_vivo() const {
    return vida > 0;
}

void Guerrero::set_armadura(int nueva_armadura){
    armadura = nueva_armadura;
}

void Guerrero::atacar(shared_ptr<Personaje> atacante, shared_ptr<Personaje> objetivo) {
    if (!esta_vivo()) {
        cout << nombre << " no puede atacar porque esta muerto." << endl;
        return;
    }
    
    if (!objetivo) {
        cout << "No hay objetivo para atacar." << endl;
        return;
    }

    if (rand() % 100 < atacante->get_armas().first->get_precision()) {
        int dano_base = fuerza + atacante->get_armas().first->get_dano_base();
        
        if (rand() % 100 < atacante->get_armas().first->get_probabilidad_critico()) {
            dano_base *= 2;
            cout << atacante->get_nombre() << " realiza un golpe critico!" << endl;
        }
        
        cout << atacante->get_nombre() << " ataca con " << dano_base << " puntos de daño." << endl;
        objetivo->recibir_dano(dano_base);
    } else {
        cout << atacante->get_nombre() << " falla el ataque!" << endl;
    }
}

pair<shared_ptr<Arma>, shared_ptr<Arma>> Guerrero::get_armas() const {
    return armas;
}

void Guerrero::set_armas(pair<shared_ptr<Arma>, shared_ptr<Arma>> nuevas_armas) {
    armas = nuevas_armas;
}
