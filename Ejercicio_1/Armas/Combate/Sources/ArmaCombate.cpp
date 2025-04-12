#include "../Headers/ArmaCombate.hpp"
#include <iostream>

using namespace std;

class Personaje;

ArmaCombate::ArmaCombate(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision):
    nombre(nombre),
    dano_base(dano_base),
    durabilidad(durabilidad),
    velocidad_ataque(velocidad_ataque),
    precision(precision)
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

bool ArmaCombate::get_esta_destruida() const {
    return durabilidad <= 0;
}

void ArmaCombate::set_durabilidad(int nueva_durabilidad) {
    durabilidad = nueva_durabilidad;
}

void ArmaCombate::mostrar_info() {
    cout << "=== Información del Arma de Combate ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Daño base: " << dano_base << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Velocidad de ataque: " << velocidad_ataque << endl;
    cout << "Precisión: " << precision << endl;
    cout << "Estado: " << (get_esta_destruida() ? "Destruida" : "Funcional") << endl;
}












