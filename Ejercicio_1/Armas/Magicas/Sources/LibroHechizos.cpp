#include "../Headers/LibroHechizos.hpp"
#include <iostream>

using namespace std;

LibroHechizos::LibroHechizos(string nombre, int dano_base, int durabilidad)
    : ArmaMagica(nombre, dano_base, durabilidad, 2, 80, 40)
    {}

void LibroHechizos::atacar() const{
    cout << "Atacando con Libro de Hechizos..." << endl;
}