#include "../Headers/Paladin.hpp"
#include "../../../Armas/Combate/Headers/garrote.hpp"

Paladin::Paladin(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : Guerrero(nombre, 105, 55, 60, armas)
{}

void Paladin::mostrar_info() const {
    cout << "=== Paladin ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}