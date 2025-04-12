#include "../Headers/ArmaMagica.hpp"
#include "../../../Personajes/Personaje.hpp"
#include <iostream>

using namespace std;

ArmaMagica::ArmaMagica(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int probabilidad_critico):
    nombre(nombre),
    dano_base(dano_base),
    durabilidad(durabilidad),
    velocidad_ataque(velocidad_ataque),
    precision(precision),
    probabilidad_critico(probabilidad_critico)
{}

string ArmaMagica::get_nombre() const {
    return nombre;
}

int ArmaMagica::get_dano_base() const {
    return dano_base;
}

int ArmaMagica::get_durabilidad() const {
    return durabilidad;
}

int ArmaMagica::get_velocidad_ataque() const {
    return velocidad_ataque;
}

int ArmaMagica::get_precision() const {
    return precision;
}

int ArmaMagica::get_probabilidad_critico() const {
    return probabilidad_critico;
}

bool ArmaMagica::get_esta_destruida() const {
    return durabilidad <= 0;
}

void ArmaMagica::set_durabilidad(int nueva_durabilidad) {
    durabilidad = nueva_durabilidad;
}

void ArmaMagica::mostrar_info() const {
    cout << "=== Información del Arma Mágica ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Daño base: " << dano_base << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Velocidad de ataque: " << velocidad_ataque << endl;
    cout << "Precisión: " << precision << endl;
    cout << "Probabilidad de crítico: " << probabilidad_critico << endl;
    cout << "Estado: " << (get_esta_destruida() ? "Destruida" : "Funcional") << endl;
}
