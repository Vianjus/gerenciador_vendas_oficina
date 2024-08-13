#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

class Pessoa {
protected: 
    string nome;
    string cpf;

public: 
    Pessoa(string nome, string cpf);
    virtual ~Pessoa();

    void setNome(string nome);
    string getNome() const;

    void setCpf(string cpf);
    string getCpf() const;   
};

#endif // PESSOA_H