#include "../Headers/Guerreros.hpp"
#include "../../../Armas/Magicas/Headers/ArmaMagica.hpp"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

Guerrero::Guerrero(string nombre, int vida, int resistencia_fisica, int resistencia_magica, int armadura, int fuerza, shared_ptr<Arma> arma)
    : nombre(nombre), vida(vida), resistencia_fisica(resistencia_fisica),
      resistencia_magica(resistencia_magica), armadura(armadura), fuerza(fuerza), arma(arma) {}

// Métodos heredados de Personaje
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

void Guerrero::recibir_dano(int dano, bool es_dano_magico) {
    int reduccion_dano;
    if (es_dano_magico) {
        reduccion_dano = (resistencia_magica / 2);
    } else {
        reduccion_dano = armadura + (resistencia_fisica / 2);
    }
    
    int dano_final = dano - reduccion_dano;
    
    if (dano_final < 0) {
        dano_final = 0;
        cout << nombre << " bloquea todo el daño con su armadura y resistencia!" << endl;
    } else {
        cout << nombre << " recibe " << dano_final << " puntos de daño " << (es_dano_magico ? "mágico" : "físico") << "!" << endl;
    }
    
    vida -= dano_final;
    
    if (vida <= 0) {
        vida = 0;
        cout << nombre << " ha caído en combate!" << endl;
    }
}

bool Guerrero::esta_vivo() const {
    return vida > 0;
}

void Guerrero::atacar(Personaje* objetivo) {
    if (!esta_vivo()) {
        cout << nombre << " está muerto y no puede atacar." << endl;
        return;
    }

    if (!objetivo) {
        cout << "No hay objetivo válido para atacar." << endl;
        return;
    }

    if (!objetivo->esta_vivo()) {
        cout << "El objetivo ya está muerto." << endl;
        return;
    }

    if (!arma) {
        cout << nombre << " no tiene un arma equipada." << endl;
        return;
    }

    bool es_dano_magico = dynamic_pointer_cast<ArmaMagica>(arma) != nullptr;
    int dano = arma->get_dano_base() + fuerza;
    objetivo->recibir_dano(dano, es_dano_magico);
}

void Guerrero::mostrar_info() const {
    cout << "=== Información del Guerrero ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Resistencia Física: " << resistencia_fisica << endl;
    cout << "Resistencia Mágica: " << resistencia_magica << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Fuerza: " << fuerza << endl;
    if (arma) {
        cout << "\nArma equipada:" << endl;
        arma->mostrar_info();
    } else {
        cout << "Sin arma equipada" << endl;
    }
}

// Métodos específicos de Guerrero
int Guerrero::get_resistencia_fisica() const {
    return resistencia_fisica;
}

void Guerrero::set_resistencia_fisica(int nueva_resistencia) {
    resistencia_fisica = nueva_resistencia;
}

int Guerrero::get_resistencia_magica() const {
    return resistencia_magica;
}

void Guerrero::set_resistencia_magica(int nueva_resistencia) {
    resistencia_magica = nueva_resistencia;
}

int Guerrero::get_armadura() const {
    return armadura;
}

void Guerrero::set_armadura(int nueva_armadura) {
    armadura = nueva_armadura;
}

int Guerrero::get_fuerza() const {
    return fuerza;
}

void Guerrero::set_fuerza(int nueva_fuerza) {
    fuerza = nueva_fuerza;
}

shared_ptr<Arma> Guerrero::get_arma() const {
    return arma;
}

void Guerrero::set_arma(shared_ptr<Arma> nueva_arma) {
    arma = nueva_arma;
}
