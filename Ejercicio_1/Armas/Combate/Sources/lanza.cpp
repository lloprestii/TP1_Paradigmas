#include "../Headers/lanza.hpp"
#include <iostream>

using namespace std;

Lanza::Lanza(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 7, 80, 25) 
    {} 

void Lanza::atacar() const{
    cout << "Atacando con Lanza..." << endl;
}