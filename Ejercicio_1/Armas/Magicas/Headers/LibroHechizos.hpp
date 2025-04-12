#include "ArmaMagica.hpp"

class LibroHechizos : public ArmaMagica {
    public:
        LibroHechizos(string nombre, int dano_base, int durabilidad);
        void atacar() const override;
};
