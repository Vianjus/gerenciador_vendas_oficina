#include "funcionario.h"

Funcionario::Funcionario(string nome, string cpf, string cargo, string senha) : Pessoa(nome, cpf), cargo(cargo), senha(senha) {}

Funcionario::~Funcionario() {}

void Funcionario::setCargo(string cargo) {
    this->cargo = cargo;
}

string Funcionario::getCargo() {
    return cargo;
}

void Funcionario::setSenha(string senha) {
    this->senha = senha;
}

string Funcionario::getSenha() {
    return senha;
}