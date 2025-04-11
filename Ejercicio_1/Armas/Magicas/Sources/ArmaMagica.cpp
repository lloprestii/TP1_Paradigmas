#include "../Headers/ArmaMagica.hpp"
#include <iostream>

using namespace std;

ArmaMagica::ArmaMagica(const string& nombre, int dano_base, int durabilidad, 
                       int velocidad_ataque, int precision, int dano_magico, 
                       int mana_requerido, int probabilidad_critico, bool esta_destruida,
                       int poder_curacion):
    nombre(nombre),
    dano_base(dano_base),
    durabilidad(durabilidad),
    velocidad_ataque(velocidad_ataque),
    precision(precision),
    dano_magico(dano_magico),
    mana_requerido(mana_requerido),
    probabilidad_critico(probabilidad_critico),
    esta_destruida(esta_destruida),
    poder_curacion(poder_curacion)
{}

// Implementación de los métodos virtuales puros de Arma
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
    return esta_destruida;
}

// Implementación de getters adicionales
int ArmaMagica::get_dano_magico() const {
    return dano_magico;
}

int ArmaMagica::get_mana_requerido() const {
    return mana_requerido;
}

int ArmaMagica::get_poder_curacion() const {
    return poder_curacion;
}

// Implementación de setters
void ArmaMagica::set_durabilidad(int nueva_durabilidad) {
    durabilidad = nueva_durabilidad;
    if (durabilidad <= 0) {
        esta_destruida = true;
        durabilidad = 0;
    }
}

void ArmaMagica::set_dano_magico(int dano_magico) {
    this->dano_magico = dano_magico;
}

void ArmaMagica::set_mana_requerido(int mana_requerido) {
    this->mana_requerido = mana_requerido;
}

void ArmaMagica::set_poder_curacion(int poder_curacion) {
    this->poder_curacion = poder_curacion;
}

// Implementación de métodos de información
void ArmaMagica::mostrar_info() {
    cout << "=== Información del Arma Mágica ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Daño base: " << dano_base << endl;
    cout << "Daño mágico: " << dano_magico << endl;
    cout << "Poder de curación: " << poder_curacion << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Velocidad de ataque: " << velocidad_ataque << endl;
    cout << "Precisión: " << precision << endl;
    cout << "Mana requerido: " << mana_requerido << endl;
    cout << "Probabilidad crítico: " << probabilidad_critico << "%" << endl;
    cout << "Estado: " << (esta_destruida ? "Destruida" : "Funcional") << endl;
}

void ArmaMagica::mostrar_estado() {
    cout << "=== Estado del Arma Mágica ===" << endl;
    cout << "Durabilidad actual: " << durabilidad << endl;
    cout << "Estado: " << (esta_destruida ? "Destruida" : "Funcional") << endl;
}