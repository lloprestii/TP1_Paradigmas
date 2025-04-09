#pragma once
#include <string>
#include "../Arma.hpp"

using namespace std;

class ArmaMagica : public Arma {
    private:
        // Atributos
        int mana_requerido;
        string elemento_magico;
        int poder_magico;
        bool encantada;
        float tiempo_recarga;

    public:
        ArmaMagica(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, 
                  int precision, int mana_requerido, const string& elemento_magico, 
                  int poder_magico, bool encantada, float tiempo_recarga);

        ~ArmaMagica() override = default;

        // Getters
        int get_mana_requerido() const;
        string get_elemento_magico() const;
        int get_poder_magico() const;
        bool get_encantada() const;
        float get_tiempo_recarga() const;

        // Setters
        void set_mana_requerido(int mana);
        void set_elemento_magico(const string& elemento);
        void set_poder_magico(int poder);
        void set_encantada(bool encantada);
        void set_tiempo_recarga(float tiempo);

        // Metodos propios de la clase
        void encantar();
        void lanzar_hechizo();
        void recargar_mana();
        void cambiar_elemento(const string& nuevo_elemento);
        void aumentar_poder_magico(int cantidad);

        // Metodos heredados de Arma
        void usar(Personaje* personaje) override;
        void mostrar_info() override;
        void recargar() override;
        void reparar() override;
        void mejorar() override;
        
};
