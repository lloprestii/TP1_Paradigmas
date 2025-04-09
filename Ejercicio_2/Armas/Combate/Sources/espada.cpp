#include "../Headers/espada.hpp"

using namespace std;

Espada::Espada(const string& nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 8, 85, 2, 20, false, 10, 5) {}
