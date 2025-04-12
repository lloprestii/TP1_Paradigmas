#include "../Headers/espada.hpp"
#include <iostream>

using namespace std;

Espada::Espada(const string& nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 8, 85, 2, 20, false, 10, 5, false) 
    {} 

void Espada::atacar() const{
    cout << "Atacando con Espada..." << endl;
}