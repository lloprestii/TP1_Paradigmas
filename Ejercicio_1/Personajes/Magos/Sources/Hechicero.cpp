#include "../Headers/Hechicero.hpp"
#include "../../../Armas/Magicas/Headers/Baston.hpp"

Hechicero::Hechicero(string nombre)
    : Magos(nombre, 90, 95, 30, 45, 20, 100, make_shared<Baston>("Baston", 25, 100))
    {}
    