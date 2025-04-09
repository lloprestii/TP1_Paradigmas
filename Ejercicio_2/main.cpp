#include <iostream>
#include "Armas/Combate/Headers/ArmaCombate.hpp"
#include "Armas/Combate/Headers/espada.hpp"
using namespace std;

int main() {
    cout << "=== Prueba de ArmaCombate ===" << endl;
    
    Espada espada("Espada de Hierro", 10, 100);
    espada.mostrar_info();
    espada.mostrar_estado();
    espada.bloquear();
    espada.mostrar_estado();
    espada.lanzar_arma();
    espada.mostrar_estado();
    espada.afilar();
    espada.mostrar_estado();
    espada.reparar();
    espada.mostrar_estado();
    espada.mostrar_info();
    
    return 0;
}