#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include <memory>
#include "../Ejercicio_1/Personajes/Personaje.hpp"

int numero_aleatorio(int min, int max){ 
    return min + rand() % (max - min + 1);
}

enum class Golpes{
    GolpeFuerte,
    GolpeRapido,
    DefensaYGolpe
};



void Resultado(shared_ptr<Personaje> Personaje1, shared_ptr<Personaje> Personaje2, int opcion, Golpes golpeAleatorio){
        if(opcion == 0 && golpeAleatorio == Golpes::GolpeRapido){
            cout << "El " << Personaje1->get_nombre() << " ataca con " << Personaje1->get_armas().first->get_nombre() << " y hace 10 puntos de dano." << endl;
            Personaje2->recibir_dano(10);
        }
        else if(opcion == 1 && golpeAleatorio == Golpes::GolpeFuerte){
            cout << "El " << Personaje2->get_nombre() << " ataca con " << Personaje2->get_armas().first->get_nombre() << " y hace 10 puntos de dano." << endl;
            Personaje1->recibir_dano(10);
        }
        else if(opcion == 1 && golpeAleatorio == Golpes::DefensaYGolpe){
            cout << "El " << Personaje1->get_nombre() << " ataca con " << Personaje1->get_armas().first->get_nombre() << " y hace 10 puntos de dano." << endl;
            Personaje2->recibir_dano(10);
        }
        else if(opcion == 2 && golpeAleatorio == Golpes::GolpeRapido){
            cout << "El " << Personaje2->get_nombre() << " ataca con " << Personaje2->get_armas().first->get_nombre() << " y hace 10 puntos de dano." << endl;
            Personaje1->recibir_dano(10);
        }
        else if(opcion == 2 && golpeAleatorio == Golpes::GolpeFuerte){
            cout << "El " << Personaje1->get_nombre() << " ataca con " << Personaje1->get_armas().first->get_nombre() << " y hace 10 puntos de dano." << endl;
            Personaje2->recibir_dano(10);            
        }
        else if(opcion == 0 && golpeAleatorio == Golpes::DefensaYGolpe){
             cout << "El " << Personaje2->get_nombre() << " ataca con " << Personaje2->get_armas().first->get_nombre() << " y hace 10 puntos de dano." << endl;
            Personaje1->recibir_dano(10);           
        }
        else if((opcion == 0 && golpeAleatorio == Golpes::GolpeFuerte) || (opcion == 1 && golpeAleatorio == Golpes::GolpeRapido) || (opcion == 2 && golpeAleatorio == Golpes::DefensaYGolpe)){
            cout << "Mismo golpe lanzado, esto es un empate, nadie recibe dano." << endl;
        }
        else{
            cout << "La opcion ingresada no es valida, nadie recibe dano." << endl;
        }
}

