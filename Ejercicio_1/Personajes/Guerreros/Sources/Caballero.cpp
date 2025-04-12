#include "../Headers/Caballero.hpp"
#include "../../../Armas/Combate/Headers/espada.hpp"

Caballero::Caballero(string nombre)
    : Guerrero(nombre, 110, 60, 70, make_shared<Espada>("Espada", 25, 80))
{}

void Caballero::mostrar_info() const {
    cout << "=== Caballero ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma: " << arma->get_nombre() << endl;
}
