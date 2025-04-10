#include "../Headers/hacha_doble.hpp"

HachaDoble::HachaDoble(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 3, 60, 2, 25, true, 18, 12)
    {}