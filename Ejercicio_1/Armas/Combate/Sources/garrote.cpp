#include "../Headers/garrote.hpp"
#include <iostream>

using namespace std;

Garrote::Garrote(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 4, 60, 1, 0, false, 15, 7, false) 
    {}

void Garrote::atacar() const{
    cout << "Atcando con Garrote..." << endl;
}