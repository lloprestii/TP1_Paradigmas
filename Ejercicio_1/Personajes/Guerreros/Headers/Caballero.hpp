#include "Guerreros.hpp"

class Caballero : public Guerrero {
    public:
        Caballero(string nombre);
        void mostrar_info() const override;
};
