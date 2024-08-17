#ifndef MECANICO_H
#define MECANICO_H

#include "interface.h"
#include "funcionario.h"

class Interface;

class Mecanico : public Funcionario {
public:
    Mecanico(string nome, string cpf, string senha);
    virtual ~Mecanico();
    void acessarSistemaMecanico(Interface& );
    void imprimirOrdensPendentes(Interface& );
    void finalizarOrdem(Interface& sistema) const;
};

#endif // MECANICO_H
