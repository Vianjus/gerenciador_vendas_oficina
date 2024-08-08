#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"

class Funcionario : public Pessoa {
protected: 
    string cargo;

public:
    Funcionario(string nome, string cpf, string cargo);
    virtual ~Funcionario();

    void setCargo(string cargo);
    string getCargo();    
};

#endif // FUNCIONARIO_H