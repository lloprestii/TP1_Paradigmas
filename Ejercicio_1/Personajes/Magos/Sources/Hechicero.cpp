#include "../Headers/Hechicero.hpp"
#include "../../../Armas/Magicas/Headers/Baston.hpp"

Hechicero::Hechicero(string nombre)
    : Magos(nombre, 90, 100, 30, make_shared<Baston>("Baston", 25, 100))
{}

void Hechicero::mostrar_info() const {
    cout << "=== Hechicero ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma: " << arma->get_nombre() << endl;
}