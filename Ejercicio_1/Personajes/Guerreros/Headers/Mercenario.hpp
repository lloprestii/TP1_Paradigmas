#include "Guerreros.hpp"

class Mercenario : public Guerrero {
    public:
        Mercenario(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};
