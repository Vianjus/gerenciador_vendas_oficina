#include "Item.h"

Item::Item(string descricao, double preco) : descricao(descricao), preco(preco) {}

Item::~Item() {}

void Item::setDescricao(string descricao) {
    this->descricao = descricao;
}

string Item::getDescricao() {
    return descricao;
}

void Item::setPreco(double preco) {
    this->preco = preco;
}

double Item::getPreco() {
    return preco;
}
