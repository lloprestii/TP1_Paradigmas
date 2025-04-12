#include "../Headers/Pocion.hpp"
#include <iostream>

using namespace std;

Pocion::Pocion(string nombre, int dano_base, int durabilidad)
    : ArmaMagica(nombre, dano_base, durabilidad, 8, 70, 15, 30, 25, false, 0)
    {}

void Pocion::atacar() const{
    cout << "Atacando con Pocion..." << endl;
}