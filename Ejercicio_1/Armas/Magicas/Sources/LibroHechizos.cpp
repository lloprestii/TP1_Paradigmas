#include "../Headers/LibroHechizos.hpp"

LibroHechizos::LibroHechizos(string nombre, int dano_base, int durabilidad)
    : ArmaMagica(nombre, dano_base, durabilidad, 2, 75, 35, "Oscuridad", 90, false, 0) 
    {}

