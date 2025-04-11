#include <iostream>
#include <string>

using namespace std;

class Personaje {
    public: 
        virtual int get_vida() = 0;
        virtual void set_vida(int nueva_vida) = 0;
        virtual string get_nombre() = 0;
        virtual void set_nombre(string nuevo_nombre) = 0;
        virtual void recibir_dano(int dano) = 0;
        virtual bool esta_vivo() = 0;
        virtual void atacar(Personaje* objetivo) = 0;
        virtual void mostrar_info() = 0;
        virtual ~Personaje() = default;
};

