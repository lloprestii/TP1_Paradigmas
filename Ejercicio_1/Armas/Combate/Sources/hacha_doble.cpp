#include "../Headers/hacha_doble.hpp"

HachaDoble::HachaDoble(string nombre, int dano_base, int durabilidad) 
    : ArmaCombate(nombre, dano_base, durabilidad, 
                  70,  // velocidad_ataque
                  85,  // precision
                  2,   // alcance
                  15,  // dano_cortante
                  true, // es_doble_mano
                  25,   // probabilidad_critico
                  20)   // costo_energia
{}