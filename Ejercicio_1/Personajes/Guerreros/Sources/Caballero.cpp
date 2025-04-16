#include "../Headers/Caballero.hpp"

Caballero::Caballero(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas)
    : Guerrero(nombre, 110, 60, 70, move(armas))
{}

void Caballero::mostrar_info() const {
    cout << "=== Caballero ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}
