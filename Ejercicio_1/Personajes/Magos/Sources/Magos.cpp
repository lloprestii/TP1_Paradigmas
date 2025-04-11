#include "../Headers/Magos.hpp"
#include "../../Armas/Magicas/Headers/ArmaMagica.hpp"
#include <iostream>
#include <random>

using namespace std;

Magos::Magos(string nombre, int vida, int energia, int resistencia_fisica, int resistencia_magica, int armadura, int mana, shared_ptr<Arma> arma) : 
    nombre(nombre),
    vida(vida),
    vida_maxima(vida),
    energia(energia),
    energia_maxima(energia),
    resistencia_fisica(resistencia_fisica),
    resistencia_magica(resistencia_magica),
    armadura(armadura),
    mana(mana),
    mana_maximo(mana),
    arma(arma)
{}

// Implementación de los métodos heredados de Personaje
int Magos::get_vida() const {
    return vida;
}

int Magos::get_vida_maxima() const {
    return vida_maxima;
}

void Magos::set_vida(int nueva_vida) {
    vida = nueva_vida;
    if (vida > vida_maxima) {
        vida = vida_maxima;
    }
}

string Magos::get_nombre() const {
    return nombre;
}

void Magos::set_nombre(string nuevo_nombre) {
    nombre = nuevo_nombre;
}

int Magos::get_mana() const {
    return mana;
}

void Magos::set_mana(int nuevo_mana) {
    mana = nuevo_mana;
    if (mana > mana_maximo) {
        mana = mana_maximo;
    }
    if (mana < 0) {
        mana = 0;
    }
}

void Magos::recibir_dano(int dano) {
    // Los magos tienen mayor resistencia mágica
    int reduccion_dano = armadura + (resistencia_fisica / 2) + resistencia_magica;
    int dano_final = dano - reduccion_dano;
    
    if (dano_final < 0) {
        dano_final = 0;
        cout << nombre << " absorbe todo el daño con su armadura y resistencias!" << endl;
    } else {
        vida -= dano_final;
        if (vida < 0) {
            vida = 0;
            cout << nombre << " ha recibido " << dano_final << " puntos de daño y ha caído en combate!" << endl;
        } else {
            cout << nombre << " recibe " << dano_final << " puntos de daño!" << endl;
        }
    }
}

bool Magos::esta_vivo() const {
    return vida > 0;
}

void Magos::atacar(Personaje* objetivo) {
    if (!esta_vivo()) {
        cout << nombre << " está muerto y no puede atacar." << endl;
        return;
    }

    if (!objetivo) {
        cout << "No hay objetivo válido para atacar." << endl;
        return;
    }

    if (!objetivo->esta_vivo()) {
        cout << "El objetivo ya está muerto." << endl;
        return;
    }

    if (energia < 10) {
        cout << nombre << " está demasiado cansado para atacar." << endl;
        return;
    }

    if (!arma) {
        cout << nombre << " no tiene un arma equipada." << endl;
        return;
    }

    // Intentar convertir el arma a un arma mágica
    auto arma_magica = dynamic_pointer_cast<ArmaMagica>(arma);
    if (!arma_magica) {
        cout << nombre << " solo puede usar armas mágicas!" << endl;
        return;
    }

    if (arma_magica->get_esta_destruida()) {
        cout << "El arma está destruida y no puede ser usada." << endl;
        return;
    }

    // Verificar mana
    if (mana < arma_magica->get_mana_requerido()) {
        cout << nombre << " no tiene suficiente mana para usar " << arma_magica->get_nombre() << endl;
        return;
    }

    // Calcular probabilidad de crítico y precisión
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_critico(1, 100);
    uniform_int_distribution<> dis_precision(1, 100);
    uniform_int_distribution<> dis_accion(1, 100);

    bool es_critico = dis_critico(gen) <= arma_magica->get_probabilidad_critico();
    bool acierta = dis_precision(gen) <= arma_magica->get_precision();
    bool decidir_curar = dis_accion(gen) <= 30 && objetivo->get_vida() < objetivo->get_vida_maxima();

    if (decidir_curar) {
        // Curar al objetivo
        int poder_curacion = arma_magica->get_poder_curacion();
        if (es_critico) {
            cout << "¡CURACIÓN CRÍTICA!" << endl;
            poder_curacion *= 2;
        }

        int vida_actual = objetivo->get_vida();
        objetivo->set_vida(vida_actual + poder_curacion);
        cout << nombre << " cura a " << objetivo->get_nombre() << " por " << poder_curacion << " puntos de vida!" << endl;
    } else {
        // Atacar al objetivo
        if (acierta) {
            int dano_total = arma_magica->get_dano_base() + arma_magica->get_dano_magico();
            if (es_critico) {
                cout << "¡CRÍTICO MÁGICO!" << endl;
                dano_total *= 2;
            }
            cout << nombre << " lanza un hechizo con " << arma_magica->get_nombre() << " causando " << dano_total << " de daño!" << endl;
            objetivo->recibir_dano(dano_total);
        } else {
            cout << "¡El hechizo de " << nombre << " ha fallado!" << endl;
        }
    }

    // Consumir recursos
    mana -= arma_magica->get_mana_requerido();
    energia -= 10;
    if (energia < 0) energia = 0;

    // Desgastar el arma
    int nueva_durabilidad = arma_magica->get_durabilidad() - (decidir_curar ? 3 : 5);
    arma_magica->set_durabilidad(nueva_durabilidad);
}

void Magos::mostrar_info() const {
    cout << "=== Información del Mago ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << "/" << vida_maxima << endl;
    cout << "Energía: " << energia << "/" << energia_maxima << endl;
    cout << "Mana: " << mana << "/" << mana_maximo << endl;
    cout << "Resistencia Física: " << resistencia_fisica << endl;
    cout << "Resistencia Mágica: " << resistencia_magica << endl;
    cout << "Armadura: " << armadura << endl;
    if (arma) {
        cout << "\nArma equipada:" << endl;
        arma->mostrar_info();
    } else {
        cout << "Sin arma equipada" << endl;
    }
}

void Magos::regenerar_mana() {
    if (!esta_vivo()) return;
    
    int regeneracion = 10;
    mana += regeneracion;
    if (mana > mana_maximo) {
        mana = mana_maximo;
    }
    cout << nombre << " regenera " << regeneracion << " puntos de mana." << endl;
}

void Magos::meditar() {
    if (!esta_vivo()) return;
    
    energia += 20;
    mana += 30;
    
    if (energia > energia_maxima) energia = energia_maxima;
    if (mana > mana_maximo) mana = mana_maximo;
    
    cout << nombre << " medita y recupera energía y mana." << endl;
}

void Magos::recibir_curacion(int cantidad) {
    if (!esta_vivo()) return;
    
    vida += cantidad;
    if (vida > vida_maxima) {
        vida = vida_maxima;
    }
    cout << nombre << " ha sido curado por " << cantidad << " puntos de vida." << endl;
}        