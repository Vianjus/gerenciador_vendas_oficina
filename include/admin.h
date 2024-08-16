#ifndef ADMIN_H
#define ADMIN_H

#include "funcionario.h"
#include "interface.h" // Inclua a interface para acessar seus membro

class Interface;

class Admin : public Funcionario {
public:
    Admin(string nome, string cpf, string senha);
    ~Admin();

    void acessarSistemaAdmin(Interface& ) const;
    int telaAdmin() const;

    void modificarVendedor(Interface& ) const;
    void modificarMecanico(Interface& ) const;
    void modificarAdmin(Interface& ) const;

    void editarAdmin(Interface& ) const;

    void adicionarMecanico(Interface& ) const;
    void adicionarVendedor(Interface& ) const;

    void editarVendedor(Interface& ) const;
    void editarMecanico(Interface& ) const;

};

#endif // ADMIN_H
