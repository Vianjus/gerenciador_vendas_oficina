#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa {
protected: 
    string nome;
    string cpf;

public: 
    Pessoa(string nome, string cpf);
    virtual ~Pessoa();

    void setNome(string nome);
    string getNome();

    void setCpf(string cpf);
    string getCpf();   
};

#endif // PESSOA_H