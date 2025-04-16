#include "Guerreros.hpp"

class Paladin : public Guerrero {
    public:
        Paladin(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};
