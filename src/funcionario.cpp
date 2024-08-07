#include "Funcionario.h"

Funcionario::Funcionario(string nome, string cpf, string cargo) : Pessoa(nome, cpf), cargo(cargo) {}

Funcionario::~Funcionario() {}

void Funcionario::setCargo(string cargo) {
    this->cargo = cargo;
}

string Funcionario::getCargo() {
    return cargo;
}