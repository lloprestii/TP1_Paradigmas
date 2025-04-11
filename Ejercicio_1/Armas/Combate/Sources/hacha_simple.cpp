#include "../Headers/hacha_simple.hpp"

HachaSimple::HachaSimple(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 6, 70, 2, 25, false, 12, 6)
    {}