#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"

class Funcionario : public Pessoa {
protected: 
    string cargo;
    string senha;

public:
    Funcionario(string nome, string cpf, string cargo, string senha);
    virtual ~Funcionario();

    void setCargo(string cargo);
    string getCargo() const;

    string getSenha() const;
    void setSenha(string senha);

    friend void salvarFuncionario(const Funcionario& funcionario);
};

#endif // FUNCIONARIO_H