#include "Armas/Combate/Headers/Espada.h"
#include "Armas/Magicas/Headers/BastonMagico.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "=== DEMOSTRACIÓN DEL SISTEMA DE ARMAS ===" << std::endl << std::endl;

    // Crear una espada
    std::cout << "=== CREANDO ESPADA ===" << std::endl;
    auto espada = std::make_unique<Espada>(
        "Espada del Dragón",    // nombre
        50,                     // daño
        100,                    // durabilidad
        2.5,                    // peso
        1,                      // nivel
        2,                      // alcance
        10,                     // velocidadAtaque
        85,                     // precisión
        "Acero Valyrio",        // material
        false,                  // esDobleMano
        90,                     // longitudHoja
        "Doble Filo",           // tipoFilo
        true,                   // tieneEmpunaduraDecorada
        15,                     // velocidadGolpe
        30                      // dañoCortante
    );

    // Demostrar uso de la espada
    std::cout << "\n=== USANDO LA ESPADA ===" << std::endl;
    espada->mostrarEstado();
    espada->usar();
    espada->afilar();
    espada->realizarEstocada();
    espada->bloquear();
    espada->mostrarEstado();

    // Crear un bastón mágico
    std::cout << "\n=== CREANDO BASTÓN MÁGICO ===" << std::endl;
    auto baston = std::make_unique<BastonMagico>(
        "Bastón del Arcano",    // nombre
        40,                     // daño
        100,                    // durabilidad
        1.8,                    // peso
        1,                      // nivel
        100,                    // mana
        50,                     // poderMagico
        "Fuego",                // elemento
        5,                      // cargaMaxima
        true,                   // requiereConcentracion
        120,                    // longitud
        "Cristal de Dragón",    // materialNucleo
        true,                   // tieneGema
        20,                     // poderAmplificacion
        15                      // velocidadConjuro
    );

    // Demostrar uso del bastón
    std::cout << "\n=== USANDO EL BASTÓN ===" << std::endl;
    baston->mostrarEstado();
    baston->usar();
    baston->lanzarHechizo();
    baston->canalizarEnergia();
    baston->crearPortal();
    baston->mostrarEstado();

    // Demostrar mejoras
    std::cout << "\n=== MEJORANDO LAS ARMAS ===" << std::endl;
    espada->mejorar();
    baston->mejorar();
    
    std::cout << "\nEstado final de la espada:" << std::endl;
    espada->mostrarEstado();
    
    std::cout << "\nEstado final del bastón:" << std::endl;
    baston->mostrarEstado();

    return 0;
} 