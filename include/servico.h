#ifndef SERVICO_H
#define SERVICO_H

#include "Item.h"

class Servico : public Item {
public:
    Servico(string descricao, double preco);
    virtual ~Servico();
};

#endif // SERVICO_H