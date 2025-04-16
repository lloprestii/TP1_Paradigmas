#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../Ejercicio_2/Factory.hpp"
#include "../Ejercicio_1/Personajes/Personaje.hpp"
#include "../Ejercicio_1/Armas/Arma.hpp"
#include "auxiliares.hpp"

using namespace std;

int main(){
    system("clear");
    srand(time(0));
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
        unique_ptr<Personaje> Personaje1 = PersonajeFactory::personaje_desarmado(static_cast<Personajes>(opcion));
        system("clear");
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
        unique_ptr<Arma> armaSeleccionada = PersonajeFactory::crear_arma(static_cast<Armas>(opcion));
        Personaje1->set_armas(make_pair(move(armaSeleccionada), nullptr));

        unique_ptr<Arma> armaAleatoria = PersonajeFactory::crear_arma(static_cast<Armas>(numero_aleatorio(0, 8)));
        unique_ptr<Personaje> Personaje2 = PersonajeFactory::personaje_armado(static_cast<Personajes>(numero_aleatorio(0, 8)),make_pair(move(armaAleatoria), nullptr));

        Personaje1->set_armadura(0);
        Personaje2->set_armadura(0);
        Personaje1->set_vida(100);
        Personaje2->set_vida(100);

        while(Personaje1->esta_vivo() && Personaje2->esta_vivo()){
            cout << "El jugador 1 tiene " << Personaje1->get_vida() << " HP y el jugador 2 tiene " << Personaje2->get_vida() << " HP." << endl;
            cout << "Su opcion: (0)Golpe Fuerte, (1)Golpe Rapido, (2)Defensa y Golpe: ";
            cin >> opcion;
            Golpes golpeAleatorio = static_cast<Golpes>(numero_aleatorio(0, 2));
            Resultado(Personaje1, Personaje2, opcion, golpeAleatorio);
            cout << endl;
        }
        system("clear");
        if (Personaje1->get_vida() == 0){
            cout << "El jugador 2 gano el juego!" << endl;
        }
        else{
            cout << "El jugador 1 gano el juego!" << endl;
        }
        return 0;
    }
}