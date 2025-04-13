#include "../Headers/Hechicero.hpp"
#include "../../../Armas/Magicas/Headers/Baston.hpp"

Hechicero::Hechicero(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : Magos(nombre, 90, 100, 30, armas)
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