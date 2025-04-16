#include "../Headers/Gladiador.hpp"

Gladiador::Gladiador(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas)
    : Guerrero(nombre, 100, 70, 30, move(armas))
{}

void Gladiador::mostrar_info() const {
    cout << "=== Gladiador ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}