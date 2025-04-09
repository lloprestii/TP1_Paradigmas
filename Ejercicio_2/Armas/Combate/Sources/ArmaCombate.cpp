#include "../Headers/ArmaCombate.hpp"
#include <iostream>

using namespace std;

class Personaje;

ArmaCombate::ArmaCombate(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int alcance, int dano_cortante, bool es_doble_mano, int probabilidad_critico, int costo_energia):
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
    esta_destruida(false)
{}

// Implementacion de los metodos virtuales puros de Arma
string ArmaCombate::get_nombre() {
    return nombre;
}

int ArmaCombate::get_dano_base() {
    return dano_base;
}

int ArmaCombate::get_durabilidad() {
    return durabilidad;
}

int ArmaCombate::get_velocidad_ataque() {
    return velocidad_ataque;
}

int ArmaCombate::get_precision() {
    return precision;
}

int ArmaCombate::get_alcance() const{
    return alcance;
}

int ArmaCombate::get_dano_cortante() const{
    return dano_cortante;
}

bool ArmaCombate::get_es_doble_mano() const{
    return es_doble_mano;
}

int ArmaCombate::get_probabilidad_critico() const{
    return probabilidad_critico;
}

int ArmaCombate::get_costo_energia() const{
    return costo_energia;
}

bool ArmaCombate::get_esta_destruida() const {
    return esta_destruida;
}

void ArmaCombate::set_esta_destruida(bool esta_destruida) {
    this->esta_destruida = esta_destruida;
}

void ArmaCombate::usar(Personaje* personaje) {
    cout << "Usando arma de combate..." << endl;
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

void ArmaCombate::bloquear() {
    cout << "Bloqueando con el arma..." << endl;
    durabilidad -= 10;
    if(durabilidad < 0) {
        durabilidad = 0;
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

void ArmaCombate::afilar() {
    cout << "Afilando el arma..." << endl;
    dano_base += 10;
    if(dano_base > 100) {
        dano_base = 100;
    }
}

void ArmaCombate::mostrar_estado() {
    cout << "=== Estado del Arma de Combate ===" << endl;
    cout << "Durabilidad actual: " << durabilidad << endl;
    cout << "Estado: " << (durabilidad > 0 ? "Funcional" : "Rota") << endl;
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








