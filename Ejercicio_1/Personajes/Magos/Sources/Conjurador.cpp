#include "../Headers/Conjurador.hpp"
#include "../../../Armas/Magicas/Headers/LibroHechizos.hpp"

Conjurador::Conjurador(string nombre)
    : Magos(nombre, 70, 140, 15, make_shared<LibroHechizos>("Libro de Hechizos", 30, 60))
{}

void Conjurador::mostrar_info() const {
    cout << "=== Conjurador ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma: " << arma->get_nombre() << endl;
}