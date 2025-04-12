#include "../Headers/Brujo.hpp"
#include "../../../Armas/Magicas/Headers/Amuleto.hpp"

Brujo::Brujo(string nombre) 
    : Magos(nombre, 80, 120, 25, make_shared<Amuleto>("Amuleto", 15, 80))
{}

void Brujo::mostrar_info() const {
    cout << "=== Brujo ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Arma: " << arma->get_nombre() << endl;
}