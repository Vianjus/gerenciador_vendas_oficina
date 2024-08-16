#ifndef MECANICO_H
#define MECANICO_H

#include "funcionario.h"
#include "interface.h"

class interface;

class Mecanico : public Funcionario {
public:
    Mecanico(string nome, string cpf, string senha);
    void acessarSistemaMecanico(Interface& );
    void imprimirOrdensPendentes(Interface& );
    void finalizarOrdem(Interface& sistema) const;
};

#endif // MECANICO_H
