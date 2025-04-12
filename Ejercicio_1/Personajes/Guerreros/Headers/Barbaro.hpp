#include "Guerreros.hpp"


class Barbaro : public Guerrero {
    public:
        Barbaro(string nombre);
        void mostrar_info() const override;
};


