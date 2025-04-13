#include "../Headers/Gladiador.hpp"
#include "../../../Armas/Combate/Headers/lanza.hpp"

Gladiador::Gladiador(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : Guerrero(nombre, 100, 70, 30, armas)
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