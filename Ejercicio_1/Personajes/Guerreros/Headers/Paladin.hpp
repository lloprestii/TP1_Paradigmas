#include "Guerreros.hpp"

class Paladin : public Guerrero {
    public:
        Paladin(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};
