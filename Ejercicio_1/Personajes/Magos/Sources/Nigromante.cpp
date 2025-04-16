#include "../Headers/Nigromante.hpp"

Nigromante::Nigromante(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas)
    : Magos(nombre, 60, 150, 10, move(armas))
{}

void Nigromante::mostrar_info() const {
    cout << "=== Nigromante ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}
