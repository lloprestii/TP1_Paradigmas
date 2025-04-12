#include "../Headers/hacha_simple.hpp"
#include <iostream>

using namespace std;

HachaSimple::HachaSimple(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 6, 70) 
    {} 

void HachaSimple::atacar() const{
    cout << "Atacando con Hacha Simple..." << endl;
}