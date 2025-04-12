#include "../Headers/Baston.hpp"
#include <iostream>

using namespace std;

Baston::Baston(string nombre, int dano_base, int durabilidad)
    : ArmaMagica(nombre, dano_base, durabilidad, 6, 90) 
    {}

void Baston::atacar() const{
    cout << "Atacando con Baston..." << endl;
}
