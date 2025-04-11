#include "../Headers/Guerreros.hpp"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

Guerrero::Guerrero(string nombre, int vida, int resistencia_fisica, int resistencia_magica, int armadura, int fuerza, shared_ptr<Arma> arma)
    : nombre(nombre), vida(vida), resistencia_fisica(resistencia_fisica),
      resistencia_magica(resistencia_magica), armadura(armadura), fuerza(fuerza), arma(arma) {}

// Métodos heredados de Personaje
int Guerrero::get_vida() {
    return vida;
}

void Guerrero::set_vida(int nueva_vida) {
    vida = nueva_vida;
}

string Guerrero::get_nombre() {
    return nombre;
}

void Guerrero::set_nombre(string nuevo_nombre) {
    nombre = nuevo_nombre;
}

void Guerrero::recibir_dano(int dano) {
    int reduccion_dano = armadura + (resistencia_fisica / 2);
    int dano_final = dano - reduccion_dano;
    
    if (dano_final < 0) {
        dano_final = 0;
        cout << nombre << " bloquea todo el daño con su armadura y resistencia!" << endl;
    } else {
        cout << nombre << " recibe " << dano_final << " puntos de daño!" << endl;
    }
    
    vida -= dano_final;
    
    if (vida <= 0) {
        vida = 0;
        cout << nombre << " ha caído en combate!" << endl;
    }
}

bool Guerrero::esta_vivo() {
    return vida > 0;
}

void Guerrero::atacar(Personaje* objetivo) {
    if (!esta_vivo()) {
        cout << nombre << " está muerto y no puede atacar." << endl;
        return;
    }

    if (!arma) {
        cout << nombre << " no tiene un arma equipada!" << endl;
        return;
    }

    if (arma->get_esta_destruida()) {
        cout << "El arma de " << nombre << " está rota y no puede atacar!" << endl;
        return;
    }

    srand(time(0));
    int precision = rand() % 100 + 1;
    
    if (precision > arma->get_precision()) {
        cout << nombre << " falla el ataque con " << arma->get_nombre() << "!" << endl;
        arma->set_durabilidad(arma->get_durabilidad() - 1);
        return;
    }
    
    int dano_base = fuerza + arma->get_dano_base();
    
    float bonus_velocidad = arma->get_velocidad_ataque() / 100.0;
    dano_base = dano_base + (dano_base * bonus_velocidad);
    
    int critico = rand() % 100 + 1;
    bool es_critico = critico <= arma->get_probabilidad_critico();
    
    int dano_final = dano_base;
    if (es_critico) {
        dano_final *= 2;
        cout << "¡GOLPE CRÍTICO! ";
    }
    
    cout << nombre << " ataca con " << arma->get_nombre() << " causando " << dano_final << " de daño!" << endl;
    
    objetivo->recibir_dano(dano_final);
    
    int reduccion_durabilidad = es_critico ? 3 : 2;
    int nueva_durabilidad = arma->get_durabilidad() - reduccion_durabilidad;
    arma->set_durabilidad(nueva_durabilidad);
    
    if (nueva_durabilidad <= 0) {
        cout << "¡El arma de " << nombre << " se ha roto!" << endl;
    }
}

void Guerrero::mostrar_info() {
    cout << "Guerrero: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Resistencia Física: " << resistencia_fisica << endl;
    cout << "Resistencia Mágica: " << resistencia_magica << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Arma: " << arma->get_nombre() << endl;
    cout << "Durabilidad del arma: " << arma->get_durabilidad() << endl;
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
