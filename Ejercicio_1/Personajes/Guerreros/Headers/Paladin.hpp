#include "Guerreros.hpp"

class Paladin : public Guerrero {
    public:
        Paladin(string nombre);
        void mostrar_info() const override;
};
