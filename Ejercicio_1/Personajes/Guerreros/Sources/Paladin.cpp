#include "../Headers/Paladin.hpp"
#include "../../../Armas/Combate/Headers/garrote.hpp"

Paladin::Paladin(string nombre)
    : Guerrero(nombre, 105, 40, 80, 60, 55, make_shared<Garrote>("Garrote", 18, 90))
    {}