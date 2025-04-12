#include "Guerreros.hpp"

class Mercenario : public Guerrero {
    public:
        Mercenario(string nombre);
        void mostrar_info() const override;
};
