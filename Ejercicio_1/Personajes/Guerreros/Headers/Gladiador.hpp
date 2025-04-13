#include "Guerreros.hpp"

class Gladiador : public Guerrero {
    public:
        Gladiador(string nombre, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
        void mostrar_info() const override;
};
