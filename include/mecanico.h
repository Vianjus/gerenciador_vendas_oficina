#ifndef MECANICO_H
#define MECANICO_H

#include "funcionario.h"

class Mecanico : public Funcionario {
public:
    Mecanico(string nome, string cpf, string senha);
};

#endif // MECANICO_H
