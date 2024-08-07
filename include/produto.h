#ifndef PRODUTO_H
#define PRODUTO_H

#include "Item.h"

class Produto : public Item {
public:
    Produto(string descricao, double preco);
    virtual ~Produto();
};

#endif // PRODUTO_H