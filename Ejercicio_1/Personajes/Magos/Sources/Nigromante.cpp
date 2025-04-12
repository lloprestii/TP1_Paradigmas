#include "../Headers/Nigromante.hpp"
#include "../../../Armas/Magicas/Headers/Pocion.hpp"

Nigromante::Nigromante(string nombre)
    : Magos(nombre, 60, 150, 10, make_shared<Pocion>("Pocion", 10, 50))
{}

void Nigromante::mostrar_info() const {
    cout << "=== Nigromante ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma: " << arma->get_nombre() << endl;
}
