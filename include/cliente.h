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
    string getVeiculo() const { return veiculo; };
    void adicionarOrdem(Servico* servico) { ordens.push_back(servico); };
    const vector<Servico*>& getOrdens() const;
};

#endif // CLIENTE_H
