#include "../Headers/ArmaCombate.hpp"
#include <iostream>

using namespace std;

class Personaje;

ArmaCombate::ArmaCombate(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int alcance, int dano_cortante, bool es_doble_mano, int probabilidad_critico, int costo_energia, bool esta_destruida):
    Arma(),
    nombre(nombre),
    dano_base(dano_base),
    durabilidad(durabilidad),
    velocidad_ataque(velocidad_ataque),
    precision(precision),
    alcance(alcance),
    dano_cortante(dano_cortante),
    es_doble_mano(es_doble_mano),
    probabilidad_critico(probabilidad_critico),
    costo_energia(costo_energia),
    esta_destruida(esta_destruida)
{}

string ArmaCombate::get_nombre() const {
    return nombre;
}

int ArmaCombate::get_dano_base() const {
    return dano_base;
}

int ArmaCombate::get_durabilidad() const {
    return durabilidad;
}

int ArmaCombate::get_velocidad_ataque() const {
    return velocidad_ataque;
}

int ArmaCombate::get_precision() const {
    return precision;
}

int ArmaCombate::get_probabilidad_critico() const {
    return probabilidad_critico;
}

bool ArmaCombate::get_esta_destruida() const {
    return esta_destruida;
}

int ArmaCombate::get_alcance() const {
    return alcance;
}

int ArmaCombate::get_dano_cortante() const {
    return dano_cortante;
}

bool ArmaCombate::get_es_doble_mano() const {
    return es_doble_mano;
}

int ArmaCombate::get_costo_energia() const {
    return costo_energia;
}

void ArmaCombate::set_durabilidad(int nueva_durabilidad) {
    durabilidad = nueva_durabilidad;
    if (durabilidad <= 0) {
        esta_destruida = true;
        durabilidad = 0;
    }
}

void ArmaCombate::set_alcance(int alcance) {
    this->alcance = alcance;
}

void ArmaCombate::set_dano_cortante(int dano_cortante) {
    this->dano_cortante = dano_cortante;
}

void ArmaCombate::set_es_doble_mano(bool es_doble_mano) {
    this->es_doble_mano = es_doble_mano;
}

void ArmaCombate::set_probabilidad_critico(int probabilidad_critico) {
    this->probabilidad_critico = probabilidad_critico;
}

void ArmaCombate::set_costo_energia(int costo_energia) {
    this->costo_energia = costo_energia;
}

void ArmaCombate::mostrar_info() {
    cout << "=== Información del Arma de Combate ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Daño base: " << dano_base << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Velocidad de ataque: " << velocidad_ataque << endl;
    cout << "Precisión: " << precision << endl;
    cout << "Alcance: " << alcance << endl;
    cout << "Daño cortante: " << dano_cortante << endl;
    cout << "Es doble mano: " << (es_doble_mano ? "Sí" : "No") << endl;
    cout << "Probabilidad crítico: " << probabilidad_critico << "%" << endl;
    cout << "Costo de energía: " << costo_energia << endl;
    cout << "Estado: " << (esta_destruida ? "Destruida" : "Funcional") << endl;
}

// Implementación de métodos propios
void ArmaCombate::bloquear() {
    cout << "Bloqueando con el arma..." << endl;
    durabilidad -= 10;
    if(durabilidad <= 0) {
        durabilidad = 0;
        esta_destruida = true;
    }
}

void ArmaCombate::reparar() {
    if (esta_destruida) {
        cout << "No se puede reparar un arma destruida." << endl;
        return;
    }
    cout << "El arma " << nombre << " se ha reparado." << endl;
    durabilidad += 10;
    if(durabilidad > 100){
        durabilidad = 100;
    }
    cout << "Durabilidad restante: " << durabilidad << endl;
}


void ArmaCombate::mostrar_estado() {
    cout << "=== Estado del Arma de Combate ===" << endl;
    cout << "Durabilidad actual: " << durabilidad << endl;
    cout << "Estado: " << (esta_destruida ? "Destruida" : "Funcional") << endl;
}

bool ArmaCombate::lanzar_arma() {
    if(esta_destruida) {
        cout << "El arma ya está destruida." << endl;
        return false;
    }
    cout << "Lanzando el arma..." << endl;
    esta_destruida = true;
    durabilidad = 0;
    cout << "El arma se ha destruido y no puede ser reparada." << endl;
    return true;
}












