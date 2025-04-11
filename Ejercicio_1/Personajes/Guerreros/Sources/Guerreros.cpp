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
    int dano_real = dano - (armadura + resistencia_fisica);
    if (dano_real > 0) {
        vida -= dano_real;
        if (vida < 0) vida = 0;
    }
}

bool Guerrero::esta_vivo() {
    return vida > 0;
}

void Guerrero::atacar(Personaje* objetivo) {
    if (esta_vivo()) {
        // Generador de números aleatorios
        static mt19937 gen(time(nullptr));
        uniform_int_distribution<> dis(1, 100);
        
        // Primero verificar si el ataque acierta basado en la precisión del arma
        int roll_precision = dis(gen);
        if (roll_precision > arma->get_precision()) {
            cout << nombre << " falla el ataque con " << arma->get_nombre() << "." << endl;
            return;
        }
        
        // Calcular daño base
        int dano_base = fuerza + arma->get_dano_base();
        int dano_final = dano_base;
        
        // Verificar si es un golpe crítico basado en la probabilidad de crítico del arma
        int roll_critico = dis(gen);
        if (roll_critico <= arma->get_probabilidad_critico()) {
            dano_final *= 2; // El daño se duplica en golpe crítico
            cout << "¡Golpe crítico! ";
        }
        
        cout << nombre << " ataca con " << arma->get_nombre() << " causando " << dano_final << " de daño." << endl;
        objetivo->recibir_dano(dano_final);
        
        // Reducir durabilidad del arma
        if (arma->get_durabilidad() > 0) {
            // La durabilidad se reduce más rápido con ataques críticos
            int reduccion_durabilidad = roll_critico <= arma->get_probabilidad_critico() ? 2 : 1;
            arma->set_durabilidad(arma->get_durabilidad() - reduccion_durabilidad);
        }
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
