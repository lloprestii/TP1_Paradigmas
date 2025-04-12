#include "../Headers/Barbaro.hpp"
#include "../../../Armas/Combate/Headers/hacha_doble.hpp"
#include <memory>

Barbaro::Barbaro(string nombre)
    : Guerrero(nombre, 120, 90, 20, make_shared<HachaDoble>("Hacha Doble", 35, 60))
{}

void Barbaro::mostrar_info() const {
    cout << "=== Barbaro ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma: " << arma->get_nombre() << endl;
}