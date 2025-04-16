#include <iostream>
#include <memory>
#include "Personajes/Guerreros/Headers/Barbaro.hpp"
#include "Personajes/Guerreros/Headers/Caballero.hpp"
#include "Armas/Combate/Headers/espada.hpp"
#include "Armas/Combate/Headers/hacha_doble.hpp"

using namespace std;

int main() {
    auto espada = make_unique<Espada>("Espada de Acero", 15, 100);
    auto hacha = make_unique<HachaDoble>("Hacha de Guerra", 20, 90);
    auto espada2 = make_unique<Espada>("Espada de Hierro", 10, 80);
    auto hacha2 = make_unique<HachaDoble>("Hacha de Hierro", 18, 85);
    
    auto barbaro = make_unique<Barbaro>("Grom", make_pair(std::move(espada), std::move(hacha)));
    auto caballero = make_unique<Caballero>("Arthur", make_pair(std::move(espada2), std::move(hacha2)));
    
    cout << "=== Estado Inicial ===" << endl;
    cout << "BARBARO:" << endl;
    barbaro->mostrar_info();
    cout << "\nCABALLERO:" << endl;
    caballero->mostrar_info();
    cout << endl;
    
    cout << "=== Inicio del Combate ===" << endl;
    cout << barbaro->get_nombre() << " ataca a " << caballero->get_nombre() << endl;
    barbaro->atacar(*barbaro, *caballero);
    cout << endl;
    
    cout << caballero->get_nombre() << " contraataca a " << barbaro->get_nombre() << endl;
    caballero->atacar(*caballero, *barbaro);
    cout << endl;
    
    cout << barbaro->get_nombre() << " lanza un ataque furioso!" << endl;
    barbaro->atacar(*barbaro, *caballero);
    cout << endl;
    
    cout << "=== Estado Final ===" << endl;
    cout << "BARBARO:" << endl;
    barbaro->mostrar_info();
    cout << "\nCABALLERO:" << endl;
    caballero->mostrar_info();
    
    return 0;
}