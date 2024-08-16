#include "funcionario.h"

//Construtor da classe Funcionario
Funcionario::Funcionario(string nome, string cpf, string cargo, string senha) : Pessoa(nome, cpf), cargo(cargo), senha(senha) {}

//Destrutor da classe Funcionario
Funcionario::~Funcionario() {}

//Getters e Setters
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

//Imprime as informações dos funcionários
void Funcionario::printInfo() const {
        cout << "Dados do " << cargo << ":" << endl;
        cout << "Nome: " << getNome() << endl;
        cout << "CPF: " << getCpf() << endl;
        cout << "Senha: " << getSenha() << endl;
}