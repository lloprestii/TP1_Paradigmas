#include "../Headers/Barbaro.hpp"
#include "../../../Armas/Combate/Headers/hacha_doble.hpp"
#include <memory>

Barbaro::Barbaro(string nombre)
    : Guerrero(nombre, 120, 40, 10, 20, 90, make_shared<HachaDoble>("Hacha Doble", 35, 60))
    {}