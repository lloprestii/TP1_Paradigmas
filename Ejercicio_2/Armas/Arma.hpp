#include <string>

using namespace std;

class Personaje;

class Arma {
    private:
        std::string nombre;
        int dano_base;
        int durabilidad;
        int velocidad_ataque;
        int precision;

    public:
        Arma(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision);

        string get_nombre() const;
        int get_dano_base() const;
        int get_durabilidad() const;
        int get_velocidad_ataque() const;
        int get_precision() const;
        
        void mostrar_info() const;
        void usar(Personaje* personaje);
        virtual ~Arma() = default;
};


