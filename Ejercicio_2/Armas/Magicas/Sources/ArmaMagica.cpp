#include "../Headers/ArmaMagica.hpp"
#include <iostream>

using namespace std;

ArmaMagica::ArmaMagica(string nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int mana_requerido, const string& elemento_magico, int poder_magico, bool encantada, int curacion){
    this->nombre = nombre;
    this->dano_base = dano_base;
    this->durabilidad = durabilidad;
    this->velocidad_ataque = velocidad_ataque;
    this->precision = precision;
    this->mana_requerido = mana_requerido;
    this->elemento_magico = elemento_magico;
    this->poder_magico = poder_magico;
    this->encantada = encantada;
    this->curacion = curacion;
}

// Getters
int ArmaMagica::get_mana_requerido() const {
    return mana_requerido;
}

string ArmaMagica::get_elemento_magico() const {
    return elemento_magico;
}

int ArmaMagica::get_poder_magico() const {
    return poder_magico;
}

bool ArmaMagica::get_encantada() const {
    return encantada;
}

int ArmaMagica::get_curacion() const {
    return curacion;
}

// Setters
void ArmaMagica::set_mana_requerido(int mana) {
    if (mana >= 0) {
        mana_requerido = mana;
    } else {
        cout << "Error: El mana requerido no puede ser negativo" << endl;
    }
}

void ArmaMagica::set_elemento_magico(string elemento) {
    elemento_magico = elemento;
}

void ArmaMagica::set_poder_magico(int poder) {
    if (poder >= 0) {
        poder_magico = poder;
    } else {
        cout << "Error: El poder mágico no puede ser negativo" << endl;
    }
}

void ArmaMagica::set_encantada(bool encantada) {
    this->encantada = encantada;
}

void ArmaMagica::set_curacion(int curacion) {
    if (curacion >= 0) {
        this->curacion = curacion;
    } else {
        cout << "Error: La curación no puede ser negativa" << endl;
    }
}

// Métodos heredados de Arma
string ArmaMagica::get_nombre() {
    return nombre;
}

int ArmaMagica::get_dano_base() {
    return dano_base;
}

int ArmaMagica::get_durabilidad() {
    return durabilidad;
}

int ArmaMagica::get_velocidad_ataque() {
    return velocidad_ataque;
}

int ArmaMagica::get_precision() {
    return precision;
}

void ArmaMagica::mostrar_info() {
    cout << "=== Información del Arma Mágica ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Daño Base: " << dano_base << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Velocidad de Ataque: " << velocidad_ataque << endl;
    cout << "Precisión: " << precision << endl;
    cout << "Mana Requerido: " << mana_requerido << endl;
    cout << "Elemento Mágico: " << elemento_magico << endl;
    cout << "Poder Mágico: " << poder_magico << endl;
    cout << "Estado de Encantamiento: " << (encantada ? "Encantada" : "No encantada") << endl;
    cout << "Curación: " << curacion << " puntos" << endl;
    cout << "==================================" << endl;
}

// Métodos propios de la clase
void ArmaMagica::encantar() {
    if (!encantada) {
        encantada = true;
        poder_magico += 10; // Aumenta el poder mágico al encantar
        cout << "El arma ha sido encantada. Poder mágico aumentado a " << poder_magico << endl;
    } else {
        cout << "El arma ya está encantada" << endl;
    }
}

void ArmaMagica::lanzar_hechizo() {
    if (encantada) {
        cout << "Lanzando hechizo de " << elemento_magico << " con poder " << poder_magico << endl;
        durabilidad -= 5; // El uso de magia desgasta el arma
        if (durabilidad < 0) durabilidad = 0;
    } else {
        cout << "El arma debe estar encantada para lanzar hechizos" << endl;
    }
}

void ArmaMagica::recargar_mana() {
    cout << "Recargando mana del arma..." << endl;
    // Simulamos la recarga de mana
    cout << "Mana recargado. Curación disponible: " << curacion << " puntos" << endl;
}

void ArmaMagica::cambiar_elemento(string nuevo_elemento) {
    string elemento_anterior = elemento_magico;
    elemento_magico = nuevo_elemento;
    cout << "Elemento cambiado de " << elemento_anterior << " a " << nuevo_elemento << endl;
}

void ArmaMagica::aumentar_poder_magico(int cantidad) {
    if (cantidad > 0) {
        poder_magico += cantidad;
        cout << "Poder mágico aumentado en " << cantidad << ". Nuevo poder: " << poder_magico << endl;
    } else {
        cout << "Error: La cantidad debe ser positiva" << endl;
    }
}