#include "ArmaMagica.hpp"

class Amuleto : public ArmaMagica {
    public:
        Amuleto(string nombre, int dano_base, int durabilidad);
        void atacar() const override;
};
