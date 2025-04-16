#include "Guerreros.hpp"

class Gladiador : public Guerrero {
    public:
        Gladiador(string nombre, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
        void mostrar_info() const override;
};
