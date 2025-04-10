#include "Armas/Combate/Headers/espada.hpp"
#include "Armas/Combate/Headers/garrote.hpp"
#include "Armas/Combate/Headers/hacha_doble.hpp"
#include "Armas/Combate/Headers/hacha_simple.hpp"
#include "Armas/Combate/Headers/lanza.hpp"
#include <iostream>

using namespace std;

void probar_arma(ArmaCombate& arma) {
    cout << "\n=== Probando " << arma.get_nombre() << " ===" << endl;
    
    // Mostrar información inicial
    arma.mostrar_info();
    cout << endl;

    // Probar métodos básicos
    cout << "Afilar el arma..." << endl;
    arma.afilar();
    arma.mostrar_info();
    cout << endl;

    cout << "Bloquear con el arma..." << endl;
    arma.bloquear();
    arma.mostrar_info();
    cout << endl;

    cout << "Reparar el arma..." << endl;
    arma.reparar();
    arma.mostrar_info();
    cout << endl;

    // Probar lanzar arma
    cout << "Lanzar el arma..." << endl;
    arma.lanzar_arma();
    arma.mostrar_info();
    cout << endl;

    cout << "Intentar reparar arma destruida..." << endl;
    arma.reparar();
    cout << endl;

    // Mostrar estado final
    cout << "Estado final del arma:" << endl;
    arma.mostrar_estado();
    cout << "===================================" << endl;
}

int main() {
    cout << "=== Prueba de Armas de Combate ===" << endl;

    // Probar Espada
    Espada espada("Espada Larga", 20, 100);
    probar_arma(espada);

    // Probar Garrote
    Garrote garrote("Garrote Pesado", 15, 80);
    probar_arma(garrote);

    // Probar Hacha Doble
    HachaDoble hachadoble("Hacha de Guerra", 25, 90);
    probar_arma(hachadoble);

    // Probar Hacha Simple
    HachaSimple hachasimple("Hacha de Mano", 18, 85);
    probar_arma(hachasimple);

    // Probar Lanza
    Lanza lanza("Lanza de Caballería", 22, 95);
    probar_arma(lanza);

    return 0;
}