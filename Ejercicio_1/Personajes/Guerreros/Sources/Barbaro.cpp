#include "../Headers/Barbaro.hpp"
#include "../../../Armas/Combate/Headers/hacha_doble.hpp"
#include <memory>

using namespace std;

Barbaro::Barbaro(string nombre)
    : Guerrero(nombre, 120, 40, 10, 20, 90, make_shared<HachaDoble>("Hacha Doble", 35, 60))
    {}

int Barbaro::get_vida() {
    return Guerrero::get_vida();
}

void Barbaro::set_vida(int nueva_vida) {
    Guerrero::set_vida(nueva_vida);
}

string Barbaro::get_nombre() {
    return Guerrero::get_nombre();
}

void Barbaro::set_nombre(string nuevo_nombre) {
    Guerrero::set_nombre(nuevo_nombre);
}

void Barbaro::recibir_dano(int dano) {
    int dano_real = dano - (get_armadura() + get_resistencia_fisica() * 1.5);
    if (dano_real > 0) {
        set_vida(get_vida() - dano_real);
        if (get_vida() < 0) set_vida(0);
    }
}

bool Barbaro::esta_vivo() {
    return Guerrero::esta_vivo();
}

void Barbaro::atacar(Personaje* objetivo) {
    if (esta_vivo()) {
        int dano_total = get_fuerza() + get_arma()->get_dano_base();
        objetivo->recibir_dano(dano_total);
    }
}

void Barbaro::mostrar_info() {
    cout << "Bárbaro: " << get_nombre() << endl;
    cout << "Vida: " << get_vida() << endl;
    cout << "Resistencia Física: " << get_resistencia_fisica() << endl;
    cout << "Resistencia Mágica: " << get_resistencia_magica() << endl;
    cout << "Armadura: " << get_armadura() << endl;
    cout << "Fuerza: " << get_fuerza() << endl;
    cout << "Arma: " << get_arma()->get_nombre() << endl;
}
    