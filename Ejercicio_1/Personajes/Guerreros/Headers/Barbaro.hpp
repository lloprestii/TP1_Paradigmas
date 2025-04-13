#include "Guerreros.hpp"


class Barbaro : public Guerrero {
    public:
        Barbaro(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};


