#include "Armas/Combate/Headers/ArmaCombate.hpp"
#include "Personajes/Guerreros/Headers/Barbaro.hpp"
#include "Personajes/Guerreros/Headers/Caballero.hpp"
#include "Personajes/Guerreros/Headers/Paladin.hpp"
#include "Personajes/Guerreros/Headers/Mercenario.hpp"
#include "Personajes/Guerreros/Headers/Gladiador.hpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void probar_guerrero(shared_ptr<Guerrero> guerrero, ArmaCombate& arma) {
    cout << "\n=== Probando " << guerrero->get_nombre() << " (" << typeid(*guerrero).name() << ") ===" << endl;
    
    // Mostrar estado inicial
    cout << "Estado inicial del guerrero:" << endl;
    guerrero->mostrar_info();
    
    // Mostrar arma asignada
    cout << "\nArma asignada:" << endl;
    arma.mostrar_info();
    
    // Realizar algunas acciones
    cout << "\nRealizando acciones..." << endl;
    
    // Crear un objetivo de prueba
    auto objetivo = make_shared<Barbaro>("Objetivo de prueba");
    guerrero->atacar(objetivo.get());
    
    cout << "\nRecibiendo daño..." << endl;
    guerrero->recibir_dano(20);
    
    // Probar el arma
    cout << "\nProbando el arma..." << endl;
    arma.bloquear();
    arma.afilar();
    arma.mostrar_estado();
    
    // Mostrar estado final
    cout << "\nEstado final del guerrero:" << endl;
    guerrero->mostrar_info();
}

int main() {
    // Crear armas de prueba
    ArmaCombate espada("Espada Larga", 50, 100, 75, 85, 2, 30, true, 15, 20, false);
    ArmaCombate hacha("Hacha de Guerra", 70, 90, 60, 75, 1, 40, true, 20, 25, false);
    ArmaCombate lanza("Lanza de Caballería", 45, 95, 80, 90, 3, 25, false, 10, 15, false);
    
    // Crear guerreros
    vector<shared_ptr<Guerrero>> guerreros;
    guerreros.push_back(make_shared<Barbaro>("Conan"));
    guerreros.push_back(make_shared<Caballero>("Lancelot"));
    guerreros.push_back(make_shared<Paladin>("Arturo"));
    guerreros.push_back(make_shared<Mercenario>("Drake"));
    guerreros.push_back(make_shared<Gladiador>("Spartacus"));
    
    // Probar cada guerrero con un arma diferente
    cout << "=== Iniciando pruebas de guerreros ===" << endl;
    probar_guerrero(guerreros[0], espada);  // Bárbaro con espada
    probar_guerrero(guerreros[1], lanza);   // Caballero con lanza
    probar_guerrero(guerreros[2], hacha);   // Paladín con hacha
    probar_guerrero(guerreros[3], espada);  // Mercenario con espada
    probar_guerrero(guerreros[4], hacha);   // Gladiador con hacha
    
    // Probar interacción entre guerreros
    cout << "\n=== Probando combate entre guerreros ===" << endl;
    auto barbaro = guerreros[0];
    auto caballero = guerreros[1];
    
    cout << "\nCombate entre " << barbaro->get_nombre() << " y " << caballero->get_nombre() << ":" << endl;
    
    // Mostrar estados iniciales
    cout << "\nEstados iniciales:" << endl;
    cout << barbaro->get_nombre() << ":" << endl;
    barbaro->mostrar_info();
    cout << "\n" << caballero->get_nombre() << ":" << endl;
    caballero->mostrar_info();
    
    // Realizar el combate
    cout << "\nRealizando combate..." << endl;
    barbaro->atacar(caballero.get());
    caballero->atacar(barbaro.get());
    
    // Mostrar estados finales
    cout << "\nEstados finales después del combate:" << endl;
    cout << "\n" << barbaro->get_nombre() << ":" << endl;
    barbaro->mostrar_info();
    cout << "\n" << caballero->get_nombre() << ":" << endl;
    caballero->mostrar_info();
    
    return 0;
} 