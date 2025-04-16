#include "Guerreros.hpp"


class Barbaro : public Guerrero {
    public:
        Barbaro(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};


