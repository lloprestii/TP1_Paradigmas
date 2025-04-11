#include "../Headers/Conjurador.hpp"
#include "../../../Armas/Magicas/Headers/LibroHechizos.hpp"

Conjurador::Conjurador(string nombre)
    : Magos(nombre, 70, 110, 15, 65, 8, 140, make_shared<LibroHechizos>("Libro de Hechizos", 30, 60))
    {}