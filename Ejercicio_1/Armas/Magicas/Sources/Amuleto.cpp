#include "../Headers/Amuleto.hpp"
#include <iostream>

using namespace std;

Amuleto::Amuleto(string nombre, int dano_base, int durabilidad)
    : ArmaMagica(nombre, dano_base, durabilidad, 4, 95)
    {}

void Amuleto::atacar() const{
    cout << "Atacando con Amuleto..." << endl;
}


