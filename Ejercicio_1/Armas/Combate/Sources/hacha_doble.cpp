#include "../Headers/hacha_doble.hpp"

HachaDoble::HachaDoble(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 70, 85, 2, 15, true, 25, 20, false)
    {} 