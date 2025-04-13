#include "../Headers/Nigromante.hpp"
#include "../../../Armas/Magicas/Headers/Pocion.hpp"

Nigromante::Nigromante(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : Magos(nombre, 60, 150, 10, armas)
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
