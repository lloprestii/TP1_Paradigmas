#include "../Headers/garrote.hpp"
#include <iostream>

using namespace std;

Garrote::Garrote(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 4, 60, 10) 
    {}

void Garrote::atacar() const{
    cout << "Atacando con Garrote..." << endl;
}