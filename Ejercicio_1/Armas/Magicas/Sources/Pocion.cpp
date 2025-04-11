#include "../Headers/Pocion.hpp"

Pocion::Pocion(string nombre, int dano_base, int durabilidad)
    : ArmaMagica(nombre, dano_base, durabilidad, 9, 65, 5, "Hielo", 30, false, 15) 
    {}

