#include "../Headers/Mercenario.hpp"
#include "../../../Armas/Combate/Headers/hacha_simple.hpp"

Mercenario::Mercenario(string nombre)
    : Guerrero(nombre, 90, 85, 30, make_shared<HachaSimple>("Hacha Simple", 22, 50))
{}

void Mercenario::mostrar_info() const {
    cout << "=== Mercenario ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
}