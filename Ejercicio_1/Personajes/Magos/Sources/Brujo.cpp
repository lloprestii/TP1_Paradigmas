#include "../Headers/Brujo.hpp"
#include "../../../Armas/Magicas/Headers/Amuleto.hpp"

Brujo::Brujo(string nombre) 
    : Magos(nombre, 80, 100, 25, 50, 10, 120, make_shared<amuleto>("Amuleto", 15, 80))
    {}