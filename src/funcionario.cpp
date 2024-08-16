#include "funcionario.h"

Funcionario::Funcionario(string nome, string cpf, string cargo, string senha) : Pessoa(nome, cpf), cargo(cargo), senha(senha) {}

Funcionario::~Funcionario() {}

void Funcionario::setCargo(string cargo) {
    this->cargo = cargo;
}

string Funcionario::getCargo() const {
    return cargo;
}

void Funcionario::setSenha(string senha) {
    this->senha = senha;
}

string Funcionario::getSenha() const {
    return senha;
}

void Funcionario::printInfo() const {
        cout << "Dados do " << cargo << ":" << endl;
        cout << "Nome: " << getNome() << endl;
        cout << "CPF: " << getCpf() << endl;
        cout << "Senha: " << getSenha() << endl;
}