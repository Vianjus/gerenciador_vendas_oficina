#include "Veiculo.h"

Veiculo::Veiculo(string modelo, string placa, double km) : modelo(modelo), placa(placa), km(km) {}

Veiculo::~Veiculo() {}

void Veiculo::setModelo(string modelo) {
    this->modelo = modelo;
}

string Veiculo::getModelo() {
    return modelo;
}

void Veiculo::setPlaca(string placa) {
    this->placa = placa;
}

string Veiculo::getPlaca() {
    return placa;
}

void Veiculo::setKm(double km) {
    this->km = km;
}

double Veiculo::getKm() {
    return km;
}
