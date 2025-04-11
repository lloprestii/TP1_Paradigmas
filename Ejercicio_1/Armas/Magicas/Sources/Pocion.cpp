#include "../Headers/Pocion.hpp"

Pocion::Pocion(string nombre, int dano_base, int durabilidad)
    : ArmaMagica(nombre, dano_base, durabilidad, 8, 70, 15, 30, 25, false, 0)
    {}
