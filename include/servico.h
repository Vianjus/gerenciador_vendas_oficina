#ifndef SERVICO_H
#define SERVICO_H

#include "item.h"
#include <string>
#include <iostream>

class Servico : public Item {
    int valor; // 1. revisão - $100 || 2. manutenção - $1000
    int status; // 1. pendente || 2. finalizado
    int tipoServico;

public:
    Servico(string descricao, double preco, int tipoServico);
    virtual ~Servico();

    // Métodos de acesso
    bool isPendente() const;
    bool isFinalizado() const;
    void imprimir() const;

    void marcarComoFinalizado();
    
};

#endif // SERVICO_H
