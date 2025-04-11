#include "../Headers/Nigromante.hpp"
#include "../../../Armas/Magicas/Headers/Pocion.hpp"

Nigromante::Nigromante(string nombre)
    : Magos(nombre, 60, 120, 10, 70, 5, 150, make_shared<Pocion>("Pocion", 10, 50))
    {}


