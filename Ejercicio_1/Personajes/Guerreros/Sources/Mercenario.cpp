#include "../Headers/Mercenario.hpp"
#include "../../../Armas/Combate/Headers/hacha_simple.hpp"

Mercenario::Mercenario(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : Guerrero(nombre, 90, 85, 30, armas)
{}

void Mercenario::mostrar_info() const {
    cout << "=== Mercenario ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}