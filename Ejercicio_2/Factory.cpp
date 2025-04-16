#include "Factory.hpp"

unique_ptr<Personaje> PersonajeFactory::personaje_armado(Personajes tipo, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas){
    switch (tipo){
        case Personajes::BARBARO:
            return make_unique<Barbaro>("Barbaro", move(armas));
        case Personajes::CABALLERO:
            return make_unique<Caballero>("Caballero", move(armas));
        case Personajes::GLADIADOR:
            return make_unique<Gladiador>("Gladiador", move(armas));
        case Personajes::MERCENARIO:
            return make_unique<Mercenario>("Mercenario", move(armas));
        case Personajes::PALADIN:
            return make_unique<Paladin>("Paladin", move(armas));
        case Personajes::HECHICERO:
            return make_unique<Hechicero>("Hechicero", move(armas));
        case Personajes::CONJURADOR:
            return make_unique<Conjurador>("Conjurador", move(armas));
        case Personajes::NIGROMANTE:
            return make_unique<Nigromante>("Nigromante", move(armas));
        case Personajes::BRUJO:
            return make_unique<Brujo>("Brujo", move(armas));
        default:
            return nullptr;
    }
}

unique_ptr<Personaje> PersonajeFactory::personaje_desarmado(Personajes tipo){
    return personaje_armado(tipo, make_pair(nullptr, nullptr));
}

unique_ptr<Arma> PersonajeFactory::crear_arma(Armas tipo){
    switch (tipo){
        case Armas::ESPADA:
            return make_unique<Espada>("Espada", 10, 100);
        case Armas::HACHA_SIMPLE:
            return make_unique<HachaSimple>("Hacha Simple", 10, 100);
        case Armas::LANZA:
            return make_unique<Lanza>("Lanza", 10, 100);
        case Armas::GARROTE:
            return make_unique<Garrote>("Garrote", 10, 100);
        case Armas::LIBRO_HECHIZOS:
            return make_unique<LibroHechizos>("Libro de Hechizos", 10, 100);
        case Armas::AMULETO:
            return make_unique<Amuleto>("Amuleto", 10, 100);
        case Armas::POCION:
            return make_unique<Pocion>("Pocion", 10, 100);
        case Armas::BASTON:
            return make_unique<Baston>("Baston", 10, 100);
        case Armas::HACHA_DOBLE:
            return make_unique<HachaDoble>("Hacha Doble", 10, 100);
        default:
            return nullptr;
    }
}