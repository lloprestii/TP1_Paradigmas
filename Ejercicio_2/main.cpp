#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Factory.hpp"

using namespace std;

int numero_aleatorio(int min, int max){ 
    return min + rand() % (max - min + 1);
}

shared_ptr<Arma> crear_arma_random(string tipo){
    if (tipo == "guerrero"){
            switch(numero_aleatorio(0, 4)){
                case 0:
                    return PersonajeFactory::crear_arma(Armas::ESPADA);
                case 1:
                    return PersonajeFactory::crear_arma(Armas::HACHA_SIMPLE);
                case 2:
                    return PersonajeFactory::crear_arma(Armas::LANZA);
                case 3:
                    return PersonajeFactory::crear_arma(Armas::GARROTE);
                case 4:
                    return PersonajeFactory::crear_arma(Armas::HACHA_DOBLE);
                default:
                    return nullptr;
            }
    }
    else if (tipo == "mago"){
        switch(numero_aleatorio(0, 3)){
            case 0:
                return PersonajeFactory::crear_arma(Armas::LIBRO_HECHIZOS);
            case 1:
                return PersonajeFactory::crear_arma(Armas::AMULETO);
            case 2:
                return PersonajeFactory::crear_arma(Armas::POCION);
            case 3:
                return PersonajeFactory::crear_arma(Armas::BASTON);
            default:
                return nullptr;
        }
    }
    else{
        return nullptr;
    }
}

int main(){
    srand(time(0));
    int cantidad_guerreros = numero_aleatorio(3, 7);
    int cantidad_magos = numero_aleatorio(3, 7);

    cout << "Cantidad de guerreros: " << cantidad_guerreros << endl;
    cout << "Cantidad de magos: " << cantidad_magos << endl;

    vector<shared_ptr<Personaje>> guerreros;
    for (int i = 0; i < cantidad_guerreros; i++){
        Personajes guerrero_tipo = static_cast<Personajes>(numero_aleatorio(0, 4));
        int cantidad_armas = numero_aleatorio(0, 2);
        shared_ptr<Personaje> guerrero;
        if (cantidad_armas == 0){
            guerrero = PersonajeFactory::personaje_desarmado(guerrero_tipo);
        }
        else if (cantidad_armas == 1){
            guerrero = PersonajeFactory::personaje_armado(guerrero_tipo, make_pair(crear_arma_random("guerrero"), nullptr));
        }
        else{
            guerrero = PersonajeFactory::personaje_armado(guerrero_tipo, make_pair(crear_arma_random("guerrero"), crear_arma_random("guerrero")));
        }
        guerreros.push_back(guerrero);
    }

    vector<shared_ptr<Personaje>> magos;
    for (int i = 0; i < cantidad_magos; i++){
        Personajes mago_tipo = static_cast<Personajes>(numero_aleatorio(5, 8));
        int cantidad_armas = numero_aleatorio(0, 2);
        shared_ptr<Personaje> mago;
        if (cantidad_armas == 0){
            mago = PersonajeFactory::personaje_desarmado(mago_tipo);
        }
        else if (cantidad_armas == 1){
            mago = PersonajeFactory::personaje_armado(mago_tipo, make_pair(crear_arma_random("mago"), nullptr));
        }
        else{
            mago = PersonajeFactory::personaje_armado(mago_tipo, make_pair(crear_arma_random("mago"), crear_arma_random("mago")));
        }
        magos.push_back(mago);
    }
    
    cout << "Guerreros: " << endl;
    for (size_t i = 0; i < guerreros.size(); i++){
        guerreros[i]->mostrar_info();
    }
    cout << "Magos: " << endl;
    for (size_t i = 0; i < magos.size(); i++){
        magos[i]->mostrar_info();
    }

    return 0;
}
