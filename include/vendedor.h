#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "funcionario.h"

// Declaração antecipada da classe Interface
class Interface;

class Vendedor : public Funcionario {
public:
    Vendedor(string nome, string cpf, string senha);
    ~Vendedor();
    
    void telaInit(Interface& );
    void cadastrarCliente(Interface&);
    void gerarOrdem(Interface&);
    void visualizarAprovar(Interface&);
    void visualizarFechar(Interface&);
};

#endif // VENDEDOR_H
