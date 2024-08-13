#ifndef ADMIN_H
#define ADMIN_H

#include "funcionario.h"

class Admin : public Funcionario {
public:
    Admin(string nome, string cpf, string senha);
    ~Admin();

    void acessarSistemaAdmin() const;
};

#endif // ADMIN_H
