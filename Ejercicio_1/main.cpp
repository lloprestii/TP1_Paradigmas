#include "Personajes/Guerreros/Headers/Barbaro.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    // Crear dos bárbaros
    cout << "Creando dos bárbaros..." << endl;
    auto barbaro1 = make_shared<Barbaro>("Conan");
    auto barbaro2 = make_shared<Barbaro>("Krom");
    
    // Mostrar información inicial
    cout << "\n=== Información inicial de los Bárbaros ===" << endl;
    cout << "Bárbaro 1:" << endl;
    barbaro1->mostrar_info();
    cout << "\nBárbaro 2:" << endl;
    barbaro2->mostrar_info();
    
    // Probar el método atacar
    cout << "\n=== Probando el método atacar ===" << endl;
    cout << "Conan ataca a Krom..." << endl;
    barbaro1->atacar(barbaro2.get());
    cout << "\nEstado después del ataque:" << endl;
    cout << "Bárbaro 1:" << endl;
    barbaro1->mostrar_info();
    cout << "\nBárbaro 2:" << endl;
    barbaro2->mostrar_info();
    
    // Probar recibir daño
    cout << "\n=== Probando recibir daño ===" << endl;
    cout << "Vida de Krom antes del daño: " << barbaro2->get_vida() << endl;
    barbaro2->recibir_dano(100);
    cout << "Vida de Krom después de recibir 100 de daño: " << barbaro2->get_vida() << endl;
    
    // Probar cambiar nombre
    cout << "\n=== Probando cambiar nombre ===" << endl;
    cout << "Nombre actual de Conan: " << barbaro1->get_nombre() << endl;
    barbaro1->set_nombre("Thorgrim");
    cout << "Nuevo nombre: " << barbaro1->get_nombre() << endl;
    
    // Probar estado de vida
    cout << "\n=== Probando estado de vida ===" << endl;
    cout << "¿Conan está vivo? " << (barbaro1->esta_vivo() ? "Sí" : "No") << endl;
    cout << "¿Krom está vivo? " << (barbaro2->esta_vivo() ? "Sí" : "No") << endl;
    
    return 0;
} 