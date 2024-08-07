#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
protected:
    string descricao;
    double preco;

public:
    Item(string descricao, double preco);
    virtual ~Item();

    void setDescricao(string descricao);
    string getDescricao();

    void setPreco(double preco);
    double getPreco();
};

#endif // ITEM_H