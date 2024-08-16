#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "pessoa.h"
#include "servico.h"

using namespace std;

class Cliente : public Pessoa {
private:
    string veiculo;
    vector<Servico*> ordens; // Lista de ordens de serviço

public:
    Cliente(const string& nome, const string& veiculo); // Modifique a declaração aqui
    ~Cliente();

    void imprimirOrdensPendentes() const;
    void imprimirOrdensFinalizadas() const;
};

#endif // CLIENTE_H
