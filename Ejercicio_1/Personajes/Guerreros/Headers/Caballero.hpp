#include "Guerreros.hpp"

class Caballero : public Guerrero {
    public:
        Caballero(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};
