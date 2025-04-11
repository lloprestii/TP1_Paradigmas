#include "../Headers/Gladiador.hpp"
#include "../../../Armas/Combate/Headers/lanza.hpp"

Gladiador::Gladiador(string nombre)
    : Guerrero(nombre, 100, 50, 30, 50, 70, make_shared<Lanza>("Lanza", 28, 70))
    {}