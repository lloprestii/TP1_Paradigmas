#include "Guerreros.hpp"

class Gladiador : public Guerrero {
    public:
        Gladiador(string nombre);
        void mostrar_info() const override;
};
