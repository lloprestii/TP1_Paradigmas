#include "../Headers/Magos.hpp"
#include "../../../Armas/Magicas/Headers/ArmaMagica.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Magos::Magos(string nombre, int vida, int energia, int resistencia_fisica, int resistencia_magica, int armadura, int mana, shared_ptr<Arma> arma) : 
    nombre(nombre),
    vida(vida),
    energia(energia),
    resistencia_fisica(resistencia_fisica),
    resistencia_magica(resistencia_magica),
    armadura(armadura),
    mana(mana),
    arma(arma)
{}

int Magos::get_vida() const {
    return vida;
}

void Magos::set_vida(int nueva_vida) {
    vida = nueva_vida;
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
    if (mana < 0) {
        mana = 0;
    }
}

void Magos::recibir_dano(int dano, bool es_dano_magico) {
    int reduccion_fisica = armadura + resistencia_fisica;
    int reduccion_magica = resistencia_magica * 2;
    
    int dano_final;
    if (es_dano_magico) {
        dano_final = dano - reduccion_magica;
        if (dano_final < 0) dano_final = 0;
        
        auto arma_magica = dynamic_pointer_cast<ArmaMagica>(arma);
        if (arma_magica && !arma_magica->get_esta_destruida()) {
            int dano_magico_absorbido = dano_final * 0.2;
            mana += dano_magico_absorbido;
            cout << nombre << " absorbe " << dano_magico_absorbido << " puntos de daño mágico como mana!" << endl;
            
            dano_final -= arma_magica->get_dano_magico() / 2;
            if (dano_final < 0) dano_final = 0;
        }
    } else {
        dano_final = dano - reduccion_fisica;
        if (dano_final < 0) dano_final = 0;
    }
    
    if (dano_final == 0) {
        cout << nombre << " absorbe todo el daño con su armadura y resistencias!" << endl;
    } else {
        vida -= dano_final;
        if (vida < 0) {
            vida = 0;
            cout << nombre << " ha recibido " << dano_final << " puntos de daño " << (es_dano_magico ? "mágico" : "físico") << " y ha caído en combate!" << endl;
        } else {
            cout << nombre << " recibe " << dano_final << " puntos de daño " << (es_dano_magico ? "mágico" : "físico") << "!" << endl;
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

    auto arma_magica = dynamic_pointer_cast<ArmaMagica>(arma);
    if (!arma_magica) {
        cout << nombre << " solo puede usar armas mágicas!" << endl;
        return;
    }

    if (arma_magica->get_esta_destruida()) {
        cout << "El arma está destruida y no puede ser usada." << endl;
        return;
    }

    if (mana < arma_magica->get_mana_requerido()) {
        cout << nombre << " no tiene suficiente mana para usar " << arma_magica->get_nombre() << endl;
        return;
    }

    bool es_critico = (rand() % 100 + 1) <= arma_magica->get_probabilidad_critico();
    int poder_curacion = arma_magica->get_poder_curacion() + (arma_magica->get_dano_magico() / 2);
    if (es_critico) {
        cout << "¡CURACIÓN CRÍTICA!" << endl;
        poder_curacion *= 2;
    }

    int energia_usada = 10 - (arma_magica->get_velocidad_ataque() / 10);
    if (energia_usada < 1) energia_usada = 1;

    int vida_actual = objetivo->get_vida();
    objetivo->set_vida(vida_actual + poder_curacion);
    cout << nombre << " cura a " << objetivo->get_nombre() << " por " << poder_curacion << " puntos de vida!" << endl;

    mana -= arma_magica->get_mana_requerido();
    energia -= energia_usada;
    if (energia < 0) energia = 0;

    int nueva_durabilidad = arma_magica->get_durabilidad() - 3;
    arma_magica->set_durabilidad(nueva_durabilidad);

    if (rand() % 100 + 1 <= 30) {
        arma_magica->recargar_mana();
        cout << "¡" << arma_magica->get_nombre() << " se recarga con energía mágica!" << endl;
    }
}

void Magos::mostrar_info() const {
    cout << "=== Información del Mago ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Energía: " << energia << endl;
    cout << "Mana: " << mana << endl;
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
    cout << nombre << " regenera " << regeneracion << " puntos de mana." << endl;
}

void Magos::meditar() {
    if (!esta_vivo()) return;
    
    energia += 20;
    mana += 30;
    cout << nombre << " medita y recupera energía y mana." << endl;
}

void Magos::recibir_curacion(int cantidad) {
    if (!esta_vivo()) return;
    
    vida += cantidad;
    cout << nombre << " ha sido curado por " << cantidad << " puntos de vida." << endl;
}

int Magos::get_resistencia_fisica() const {
    return resistencia_fisica;
}

void Magos::set_resistencia_fisica(int nueva_resistencia) {
    resistencia_fisica = nueva_resistencia;
}

int Magos::get_resistencia_magica() const {
    return resistencia_magica;
}

void Magos::set_resistencia_magica(int nueva_resistencia) {
    resistencia_magica = nueva_resistencia;
}

int Magos::get_armadura() const {
    return armadura;
}

void Magos::set_armadura(int nueva_armadura) {
    armadura = nueva_armadura;
}

shared_ptr<Arma> Magos::get_arma() const {
    return arma;
}

void Magos::set_arma(shared_ptr<Arma> nueva_arma) {
    arma = nueva_arma;
}

void Magos::lanzar_hechizo() {
    if (!esta_vivo()) {
        cout << nombre << " está muerto y no puede lanzar hechizos." << endl;
        return;
    }

    auto arma_magica = dynamic_pointer_cast<ArmaMagica>(arma);
    if (!arma_magica) {
        cout << nombre << " necesita un arma mágica para lanzar hechizos." << endl;
        return;
    }

    if (mana < arma_magica->get_mana_requerido()) {
        cout << nombre << " no tiene suficiente mana para lanzar el hechizo." << endl;
        return;
    }

    arma_magica->lanzar_hechizo(this);
    mana -= arma_magica->get_mana_requerido();
    cout << nombre << " lanza un hechizo usando " << arma_magica->get_nombre() << endl;
}

void Magos::recargar_mana() {
    if (!esta_vivo()) return;
    
    int recarga = 20;
    mana += recarga;
    cout << nombre << " recarga " << recarga << " puntos de mana." << endl;
}

void Magos::mostrar_estado() const {
    cout << "\n=== Estado del Mago ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Estado: " << (esta_vivo() ? "Vivo" : "Muerto") << endl;
    cout << "Vida: " << vida << endl;
    cout << "Energía: " << energia << endl;
    cout << "Mana: " << mana << endl;
    cout << "Resistencia Física: " << resistencia_fisica << endl;
    cout << "Resistencia Mágica: " << resistencia_magica << endl;
    cout << "Armadura: " << armadura << endl;
}        