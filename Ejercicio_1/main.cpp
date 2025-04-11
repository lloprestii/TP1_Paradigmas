#include "Armas/Combate/Headers/ArmaCombate.hpp"
#include "Armas/Combate/Headers/espada.hpp"
#include "Armas/Combate/Headers/hacha_doble.hpp"
#include "Armas/Combate/Headers/lanza.hpp"
#include "Armas/Magicas/Headers/ArmaMagica.hpp"
#include "Armas/Magicas/Headers/Baston.hpp"
#include "Personajes/Guerreros/Headers/Barbaro.hpp"
#include "Personajes/Guerreros/Headers/Caballero.hpp"
#include "Personajes/Guerreros/Headers/Paladin.hpp"
#include "Personajes/Guerreros/Headers/Mercenario.hpp"
#include "Personajes/Guerreros/Headers/Gladiador.hpp"
#include "Personajes/Magos/Headers/Magos.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void realizar_combate(Personaje* atacante, Personaje* defensor) {
    cout << "\n=== " << atacante->get_nombre() << " ataca a " << defensor->get_nombre() << " ===" << endl;
    
    cout << "\nEstado inicial:" << endl;
    cout << atacante->get_nombre() << ":" << endl;
    atacante->mostrar_info();
    cout << "\n" << defensor->get_nombre() << ":" << endl;
    defensor->mostrar_info();
    
    atacante->atacar(defensor);
    
    cout << "\nEstado después del ataque:" << endl;
    cout << atacante->get_nombre() << ":" << endl;
    atacante->mostrar_info();
    cout << "\n" << defensor->get_nombre() << ":" << endl;
    defensor->mostrar_info();
}

int main() {
    // Inicializar la semilla de rand()
    srand(time(nullptr));

    // Crear armas de prueba
    Espada espada("Espada Larga", 50, 100);
    HachaDoble hacha("Hacha de Guerra", 70, 90);
    Lanza lanza("Lanza de Caballería", 45, 95);
    Baston baston("Bastón del Arcano", 30, 100);
    
    // Crear guerreros
    vector<shared_ptr<Guerrero>> guerreros;
    guerreros.push_back(make_shared<Barbaro>("Conan"));
    guerreros.push_back(make_shared<Caballero>("Lancelot"));
    guerreros.push_back(make_shared<Paladin>("Arturo"));
    guerreros.push_back(make_shared<Mercenario>("Drake"));
    guerreros.push_back(make_shared<Gladiador>("Spartacus"));
    
    // Crear magos
    vector<shared_ptr<Magos>> magos;
    magos.push_back(make_shared<Magos>("Merlín", 100, 100, 20, 50, 10, 150, make_shared<Baston>(baston)));
    magos.push_back(make_shared<Magos>("Gandalf", 120, 100, 25, 60, 15, 200, make_shared<Baston>(baston)));
    
    // Asignar armas a los guerreros
    guerreros[0]->set_arma(make_shared<Espada>(espada));  // Bárbaro con espada
    guerreros[1]->set_arma(make_shared<Lanza>(lanza));    // Caballero con lanza
    guerreros[2]->set_arma(make_shared<HachaDoble>(hacha)); // Paladín con hacha
    guerreros[3]->set_arma(make_shared<Espada>(espada));  // Mercenario con espada
    guerreros[4]->set_arma(make_shared<HachaDoble>(hacha)); // Gladiador con hacha
    
    // Crear vector de todos los personajes
    vector<Personaje*> todos_los_personajes;
    for (const auto& guerrero : guerreros) {
        todos_los_personajes.push_back(guerrero.get());
    }
    for (const auto& mago : magos) {
        todos_los_personajes.push_back(mago.get());
    }
    
    // Realizar combates entre todos los personajes
    cout << "=== Iniciando torneo de combate ===" << endl;
    
    for (size_t i = 0; i < todos_los_personajes.size(); ++i) {
        for (size_t j = 0; j < todos_los_personajes.size(); ++j) {
            if (i != j && todos_los_personajes[i]->esta_vivo() && todos_los_personajes[j]->esta_vivo()) {
                realizar_combate(todos_los_personajes[i], todos_los_personajes[j]);
            }
        }
    }
    
    // Mostrar resultados finales
    cout << "\n=== Resultados finales del torneo ===" << endl;
    for (const auto& personaje : todos_los_personajes) {
        cout << "\n" << personaje->get_nombre() << ":" << endl;
        personaje->mostrar_info();
    }
    
    return 0;
} 