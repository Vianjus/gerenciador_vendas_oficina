#include "pessoa.h"

Pessoa::Pessoa(string nome, string cpf) : nome(nome), cpf(cpf) {}

Pessoa::~Pessoa() {}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setCpf(string cpf) {
    this->cpf = cpf;
}

string Pessoa::getCpf() const {
    return cpf;
}