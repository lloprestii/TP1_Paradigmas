#include "Factory.hpp"

shared_ptr<Personaje> PersonajeFactory::personaje_armado(Personajes tipo, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas){
    switch (tipo){
        case Personajes::BARBARO:
            return make_shared<Barbaro>("Barbaro", armas);
        case Personajes::CABALLERO:
            return make_shared<Caballero>("Caballero", armas);
        case Personajes::GLADIADOR:
            return make_shared<Gladiador>("Gladiador", armas);
        case Personajes::MERCENARIO:
            return make_shared<Mercenario>("Mercenario", armas);
        case Personajes::PALADIN:
            return make_shared<Paladin>("Paladin", armas);
        case Personajes::HECHICERO:
            return make_shared<Hechicero>("Hechicero", armas);
        case Personajes::CONJURADOR:
            return make_shared<Conjurador>("Conjurador", armas);
        case Personajes::NIGROMANTE:
            return make_shared<Nigromante>("Nigromante", armas);
        case Personajes::BRUJO:
            return make_shared<Brujo>("Brujo", armas);
        default:
            return nullptr;
    }
}

shared_ptr<Personaje> PersonajeFactory::personaje_desarmado(Personajes tipo){
    return personaje_armado(tipo, make_pair(nullptr, nullptr));
}

shared_ptr<Arma> PersonajeFactory::crear_arma(Armas tipo){
    switch (tipo){
        case Armas::ESPADA:
            return make_shared<Espada>("Espada", 10, 100);
        case Armas::HACHA_SIMPLE:
            return make_shared<HachaSimple>("Hacha Simple", 10, 100);
        case Armas::LANZA:
            return make_shared<Lanza>("Lanza", 10, 100);
        case Armas::GARROTE:
            return make_shared<Garrote>("Garrote", 10, 100);
        case Armas::LIBRO_HECHIZOS:
            return make_shared<LibroHechizos>("Libro de Hechizos", 10, 100);
        case Armas::AMULETO:
            return make_shared<Amuleto>("Amuleto", 10, 100);
        case Armas::POCION:
            return make_shared<Pocion>("Pocion", 10, 100);
        case Armas::BASTON:
            return make_shared<Baston>("Baston", 10, 100);
        case Armas::HACHA_DOBLE:
            return make_shared<HachaDoble>("Hacha Doble", 10, 100);
        default:
            return nullptr;
    }
}