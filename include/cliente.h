#ifndef CLIENTE_H
#define CLIENTE_H

#include "pessoa.h"
#include "veiculo.h"
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