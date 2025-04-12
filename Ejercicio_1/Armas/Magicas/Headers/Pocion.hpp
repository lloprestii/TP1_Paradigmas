#include "ArmaMagica.hpp"

class Pocion : public ArmaMagica {
    public:
        Pocion(string nombre, int dano_base, int durabilidad);
        void atacar() const override;
};
