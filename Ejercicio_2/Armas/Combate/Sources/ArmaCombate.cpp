#include "ArmaCombate.hpp"

ArmaCombate::ArmaCombate(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int alcance, int dano_cortante, bool es_doble_mano, int probabilidad_critico, int costo_energia){
    this->nombre = nombre;
    this->dano_base = dano_base;
    this->durabilidad = durabilidad;
    this->velocidad_ataque = velocidad_ataque;
    this->precision = precision;
    this->alcance = alcance;
    this->dano_cortante = dano_cortante;
    this->es_doble_mano = es_doble_mano;
    this->probabilidad_critico = probabilidad_critico;
    this->costo_energia = costo_energia;
}

int ArmaCombate::get_alcance() const{
    return alcance;
}

int ArmaCombate::get_dano_cortante() const{
    return dano_cortante;
}

bool ArmaCombate::get_es_doble_mano() const{
    return es_doble_mano;
}

int ArmaCombate::get_probabilidad_critico() const{
    return probabilidad_critico;
}

int ArmaCombate::get_costo_energia() const{
    return costo_energia;
}

void ArmaCombate::usar(Personaje* personaje) override{
    if(personaje->get_energia() >= costo_energia){
        personaje->set_energia(personaje->get_energia() - costo_energia);
    }
    else{
        cout << "No tienes suficiente energia para usar esta arma." << endl;
    }
}

void ArmaCombate::mostrar_info() const override{
    cout << "Nombre: " << nombre << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Velocidad de ataque: " << velocidad_ataque << endl;
    cout << "Precision: " << precision << endl;
    cout << "Alcance: " << alcance << endl;
    cout << "Dano cortante: " << dano_cortante << endl;
    cout << "Es doble mano: " << es_doble_mano << endl;
    cout << "Probabilidad de critico: " << probabilidad_critico << endl;
    cout << "Costo de energia: " << costo_energia << endl;
    cout << "--------------------------------" << endl;
}

void ArmaCombate::bloquear(){
    cout << "El arma " << nombre << " bloquea el ataque del enemigo." << endl;
    durabilidad -= 10;
    if(durabilidad < 0){
        durabilidad = 0;
    }
    cout << "Durabilidad restante: " << durabilidad << endl;
}

void ArmaCombate::reparar(){
    cout << "El arma " << nombre << " se ha reparado." << endl;
    durabilidad += 10;
    if(durabilidad > 100){
        durabilidad = 100;
    }
    cout << "Durabilidad restante: " << durabilidad << endl;
}

void ArmaCombate::afilar(){
    cout << "El arma " << nombre << " se ha afilado." << endl;
    dano_base += 10;
    if(dano_base > 100){
        dano_base = 100;
    }
    cout << "Dano base restante: " << dano_base << endl;

}

void ArmaCombate::mostrar_estado(){
    cout << "Estado de la arma: " << nombre << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Velocidad de ataque: " << velocidad_ataque << endl;
    cout << "Precision: " << precision << endl;
    cout << "Alcance: " << alcance << endl;
    cout << "Dano cortante: " << dano_cortante << endl;
    cout << "--------------------------------" << endl;
}

bool ArmaCombate::lanzar_arma(){
    cout << "El arma " << nombre << " se ha lanzado." << endl;
    durabilidad = 0;
    //La probabilidad de impactar el arma lanzada es del 50%
    if(rand() % 2 == 0){
        cout << "El arma " << nombre << " ha impactado." << endl;
        return true;
    }
    else{
        cout << "El arma " << nombre << " no ha impactado." << endl;
    return false;
}








