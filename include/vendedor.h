#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "funcionario.h"

class Vendedor : public Funcionario {
public:
    Vendedor(string nome, string cpf, string senha);
};

#endif // VENDEDOR_H