#include "../Headers/Mercenario.hpp"
#include "../../../Armas/Combate/Headers/hacha_simple.hpp"

Mercenario::Mercenario(string nombre)
    : Guerrero(nombre, 90, 35, 20, 30, 85, make_shared<HachaSimple>("Hacha Simple", 22, 50))
    {}