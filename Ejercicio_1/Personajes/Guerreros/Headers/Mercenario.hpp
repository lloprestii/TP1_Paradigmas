#include "Guerreros.hpp"

class Mercenario : public Guerrero {
    public:
        Mercenario(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};
