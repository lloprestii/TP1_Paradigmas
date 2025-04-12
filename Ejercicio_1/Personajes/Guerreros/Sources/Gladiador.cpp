#include "../Headers/Gladiador.hpp"
#include "../../../Armas/Combate/Headers/lanza.hpp"

Gladiador::Gladiador(string nombre)
    : Guerrero(nombre, 100, 70, 30, make_shared<Lanza>("Lanza", 28, 70))
{}

void Gladiador::mostrar_info() const {
    cout << "=== Gladiador ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma: " << arma->get_nombre() << endl;
}