#include "../Headers/Paladin.hpp"

Paladin::Paladin(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas)
    : Guerrero(nombre, 105, 55, 60, move(armas))
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