#include "../Headers/Brujo.hpp"
#include "../../../Armas/Magicas/Headers/Amuleto.hpp"

Brujo::Brujo(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas) 
    : Magos(nombre, 80, 120, 25, armas)
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