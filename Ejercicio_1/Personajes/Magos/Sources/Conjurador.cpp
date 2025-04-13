#include "../Headers/Conjurador.hpp"
#include "../../../Armas/Magicas/Headers/LibroHechizos.hpp"

Conjurador::Conjurador(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : Magos(nombre, 70, 140, 15, armas)
{}

void Conjurador::mostrar_info() const {
    cout << "=== Conjurador ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}