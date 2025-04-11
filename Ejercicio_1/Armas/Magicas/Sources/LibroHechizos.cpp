#include "../Headers/LibroHechizos.hpp"

LibroHechizos::LibroHechizos(string nombre, int dano_base, int durabilidad)
    : ArmaMagica(nombre, dano_base, durabilidad, 2, 80, 30, 80, 5, false, 0)
    {}