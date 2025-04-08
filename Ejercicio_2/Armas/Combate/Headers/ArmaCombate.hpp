#include "Arma.hpp"

class ArmaCombate : public Arma{
    private:
        //5 atributos propios de la clase
        int alcance;
        int dano_cortante;
        bool es_doble_mano;
        int probabilidad_critico;
        int costo_energia;
        
    public:
        ArmaCombate(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int alcance, int dano_cortante, bool es_doble_mano, int probabilidad_critico, int costo_energia);

        int get_alcance() const;
        int get_dano_cortante() const;
        bool get_es_doble_mano() const;
        int get_probabilidad_critico() const;
        int get_costo_energia() const;

        void usar(Personaje* personaje) override;
        void mostrar_info() const override;
        ~ArmaCombate() override = default;

        //5 metodos propios de la clase
        void bloquear();
        void reparar();
        void afilar();
        void mostrar_estado();
        bool lanzar_arma();
};






