#include "../Headers/hacha_doble.hpp"
#include <iostream>

using namespace std;

HachaDoble::HachaDoble(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 70, 85, 2, 15, true, 25, 20, false)
    {} 

void HachaDoble::atacar() const{
    cout << "Atacando con Hacha Doble..." << endl;
}