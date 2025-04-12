#include "../Headers/hacha_doble.hpp"
#include <iostream>

using namespace std;

HachaDoble::HachaDoble(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 70, 85, 30) 
    {} 

void HachaDoble::atacar() const{
    cout << "Atacando con Hacha Doble..." << endl;
}