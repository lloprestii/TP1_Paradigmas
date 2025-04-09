#include "ArmaMagica.hpp"

ArmaMagica::ArmaMagica(const string& nombre, int dano_base, int durabilidad, int velocidad_ataque, int precision, int mana_requerido, const string& elemento_magico, int poder_magico, bool encantada, float tiempo_recarga){
    this->nombre = nombre;
    this->dano_base = dano_base;
    this->durabilidad = durabilidad;
    this->velocidad_ataque = velocidad_ataque;
    this->precision = precision;
    this->mana_requerido = mana_requerido;
    this->elemento_magico = elemento_magico;
    this->poder_magico = poder_magico;
    this->encantada = encantada;
    this->tiempo_recarga = tiempo_recarga;
}

ArmaMagica::~ArmaMagica(){
    cout << "ArmaMagica destruida" << endl;
}

int ArmaMagica::get_mana_requerido() const{
    return mana_requerido;
}

string ArmaMagica::get_elemento_magico() const{
    return elemento_magico;
}

int ArmaMagica::get_poder_magico() const{
    return poder_magico;
}

bool ArmaMagica::get_encantada() const{
    return encantada;
}

float ArmaMagica::get_tiempo_recarga() const{
    return tiempo_recarga;
}

void ArmaMagica::set_mana_requerido(int mana){
    mana_requerido = mana;
}

void ArmaMagica::set_elemento_magico(const string& elemento){
    elemento_magico = elemento;
}

void ArmaMagica::set_poder_magico(int poder){
    poder_magico = poder;
}

void ArmaMagica::set_encantada(bool encantada){
    this->encantada = encantada;
}

void ArmaMagica::set_tiempo_recarga(float tiempo){
    tiempo_recarga = tiempo;
}

void ArmaMagica::encantar(){
    if(encantada){
        cout << "La arma ya esta encantada" << endl;
    }
    else{
        encantada = true;
    }
}

void ArmaMagica::lanzar_hechizo(){
    
}

void ArmaMagica::recargar_mana(){
    
}