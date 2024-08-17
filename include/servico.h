#ifndef SERVICO_H
#define SERVICO_H

#include "item.h"
#include <string>
#include <iostream>

class Servico : public Item {
    double preco;
    int status; // 0. Avaliação || 1. pendente || 2. finalizado
    string nome;

public:
    Servico(string nome, double preco, int status);
    virtual ~Servico();

    // Métodos de acesso
    bool isValiando() const;
    bool isPendente() const;
    bool isFinalizado() const;
    void imprimir() const;

    void marcarComoPendente();
    void marcarComoFinalizado();
    
};

#endif // SERVICO_H
