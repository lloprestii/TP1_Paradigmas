#include "../Headers/Hechicero.hpp"

Hechicero::Hechicero(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas)
    : Magos(nombre, 90, 100, 30, move(armas))
{}

void Hechicero::mostrar_info() const {
    cout << "=== Hechicero ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}