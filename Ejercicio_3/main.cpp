#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../Ejercicio_2/Factory.hpp"
#include "../Ejercicio_1/Personajes/Personaje.hpp"
#include "../Ejercicio_1/Armas/Arma.hpp"

using namespace std;

int numero_aleatorio(int min, int max){ 
    return min + rand() % (max - min + 1);
}

int main(){
    system("clear");
    srand(time(NULL)); // Inicializar la semilla para números aleatorios
    int opcion;
    while(true){
        cout << "Seleccione un tipo de personaje:" << endl;
        cout << "0. Barbaro" << endl;
        cout << "1. Caballero" << endl;
        cout << "2. Gladiador" << endl;
        cout << "3. Mercenario" << endl;
        cout << "4. Paladin" << endl;
        cout << "5. Hechicero" << endl;
        cout << "6. Conjurador" << endl;
        cout << "7. Nigromante" << endl;
        cout << "8. Brujo" << endl;
        cout << "9. Salir" << endl;
        cin >> opcion;
        if(opcion == 9){
            break;
        }
        shared_ptr<Personaje> Personaje1 = PersonajeFactory::personaje_desarmado(static_cast<Personajes>(opcion));
        cout << "Has seleccionado el personaje " << Personaje1->get_nombre() << endl;
        cout << "Seleccione un tipo de arma:" << endl;
        cout << "0. Espada" << endl;
        cout << "1. Hacha Simple" << endl;
        cout << "2. Lanza" << endl;
        cout << "3. Garrote" << endl;
        cout << "4. Libro de Hechizos" << endl;
        cout << "5. Amuleto" << endl;
        cout << "6. Pocion" << endl;
        cout << "7. Bastón" << endl;
        cout << "8. Hacha Doble" << endl;
        cout << "9. Salir" << endl;
        cin >> opcion;
        if(opcion == 9){
            break;
        }
        shared_ptr<Arma> armaSeleccionada = PersonajeFactory::crear_arma(static_cast<Armas>(opcion));
        Personaje1->set_armas(make_pair(armaSeleccionada, nullptr));
        Personaje1->mostrar_info();

        // Crear un personaje aleatorio con un arma aleatoria
        shared_ptr<Arma> armaAleatoria = PersonajeFactory::crear_arma(static_cast<Armas>(numero_aleatorio(0, 8)));
        shared_ptr<Personaje> Personaje2 = PersonajeFactory::personaje_armado(
            static_cast<Personajes>(numero_aleatorio(0, 8)),
            make_pair(armaAleatoria, nullptr)
        );
        Personaje2->mostrar_info();
        return 0;
    }
}