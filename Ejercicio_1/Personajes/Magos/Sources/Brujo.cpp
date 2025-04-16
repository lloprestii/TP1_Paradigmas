#include "../Headers/Brujo.hpp"

Brujo::Brujo(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas) 
    : Magos(nombre, 80, 120, 25, move(armas))
{}

void Brujo::mostrar_info() const {
    cout << "=== Brujo ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma 1: " << (armas.first ? armas.first->get_nombre() : "Ninguna") << endl;
    cout << "Arma 2: " << (armas.second ? armas.second->get_nombre() : "Ninguna") << endl;
}