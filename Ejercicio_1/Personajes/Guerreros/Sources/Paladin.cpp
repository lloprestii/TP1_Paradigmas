#include "../Headers/Paladin.hpp"
#include "../../../Armas/Combate/Headers/garrote.hpp"

Paladin::Paladin(string nombre)
    : Guerrero(nombre, 105, 55, 60, make_shared<Garrote>("Garrote", 18, 90))
{}

void Paladin::mostrar_info() const {
    cout << "=== Paladin ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
}