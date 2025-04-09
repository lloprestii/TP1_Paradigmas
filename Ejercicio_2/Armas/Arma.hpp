#include <string>

using namespace std;

class Personaje;

class Arma {
    protected:
        string nombre;
        int dano_base;
        int durabilidad;
        int velocidad_ataque;
        int precision;

    public:
        Arma() = default;
        virtual ~Arma() = default;
        
        // Getters
        virtual string get_nombre() = 0;
        virtual int get_dano_base() = 0;
        virtual int get_durabilidad() = 0;
        virtual int get_velocidad_ataque() = 0;
        virtual int get_precision() = 0;
        
        // Metodos
        virtual void mostrar_info() = 0;
        virtual void usar(Personaje* personaje) = 0;
};


