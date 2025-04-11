#include "../Headers/Caballero.hpp"
#include "../../../Armas/Combate/Headers/espada.hpp"

Caballero::Caballero(string nombre)
    : Guerrero(nombre, 110, 60, 40, 70, 60, make_shared<Espada>("Espada", 25, 80))
    {}
