#include "Guerreros.hpp"

class Caballero : public Guerrero {
    public:
        Caballero(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};
