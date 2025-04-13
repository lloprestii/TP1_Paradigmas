#include "../Headers/Barbaro.hpp"
#include "../../../Armas/Combate/Headers/hacha_doble.hpp"
#include <memory>

Barbaro::Barbaro(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : Guerrero(nombre, 120, 90, 20, armas)
{}

void Barbaro::mostrar_info() const {
    cout << "=== Barbaro ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}