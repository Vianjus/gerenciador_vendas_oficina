#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
#include "Veiculo.h"
#include <vector>
using namespace std;

class Cliente : public Pessoa {
private:
    vector<Veiculo> veiculos;

public: 
    Cliente(string nome, string cpf);
    virtual ~Cliente();
};

#endif // CLIENTE_H