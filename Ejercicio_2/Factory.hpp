#include <cstdlib>
#include <iostream>
#include <memory>
#include "../Ejercicio_1/Personajes/Personaje.hpp"
#include "../Ejercicio_1/Armas/Combate/Headers/ArmaCombate.hpp"
#include "../Ejercicio_1/Armas/Magicas/Headers/ArmaMagica.hpp"
#include "../Ejercicio_1/Personajes/Guerreros/Headers/Guerreros.hpp"
#include "../Ejercicio_1/Personajes/Magos/Headers/Magos.hpp"
#include "../Ejercicio_1/Personajes/Guerreros/Headers/Barbaro.hpp"
#include "../Ejercicio_1/Personajes/Guerreros/Headers/Caballero.hpp"
#include "../Ejercicio_1/Personajes/Guerreros/Headers/Gladiador.hpp"
#include "../Ejercicio_1/Personajes/Guerreros/Headers/Mercenario.hpp"
#include "../Ejercicio_1/Personajes/Guerreros/Headers/Paladin.hpp"
#include "../Ejercicio_1/Personajes/Magos/Headers/Hechicero.hpp"
#include "../Ejercicio_1/Personajes/Magos/Headers/Conjurador.hpp"
#include "../Ejercicio_1/Personajes/Magos/Headers/Nigromante.hpp"
#include "../Ejercicio_1/Personajes/Magos/Headers/Brujo.hpp"
#include "../Ejercicio_1/Armas/Combate/Headers/hacha_simple.hpp"
#include "../Ejercicio_1/Armas/Combate/Headers/hacha_doble.hpp"
#include "../Ejercicio_1/Armas/Combate/Headers/espada.hpp"
#include "../Ejercicio_1/Armas/Combate/Headers/lanza.hpp"
#include "../Ejercicio_1/Armas/Combate/Headers/garrote.hpp"
#include "../Ejercicio_1/Armas/Magicas/Headers/LibroHechizos.hpp"
#include "../Ejercicio_1/Armas/Magicas/Headers/Amuleto.hpp"
#include "../Ejercicio_1/Armas/Magicas/Headers/Pocion.hpp"
#include "../Ejercicio_1/Armas/Magicas/Headers/Baston.hpp"

using namespace std;

enum class Personajes{
    BARBARO,
    CABALLERO,
    GLADIADOR,
    MERCENARIO,
    PALADIN,
    HECHICERO,
    CONJURADOR,
    NIGROMANTE,
    BRUJO,
};

enum class Armas{
    ESPADA,
    HACHA_SIMPLE,
    LANZA,
    GARROTE,
    LIBRO_HECHIZOS,
    AMULETO,
    POCION,
    BASTON,
    HACHA_DOBLE,
};

class PersonajeFactory{
    public:
        static shared_ptr<Personaje> personaje_armado(Personajes tipo, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        static shared_ptr<Personaje> personaje_desarmado(Personajes tipo);
        static shared_ptr<Arma> crear_arma(Armas tipo);
};