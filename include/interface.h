#ifndef INTERFACE_H
#define INTERFACE_H

#include "funcionario.h"
#include "admin.h"
#include "mecanico.h"
#include "vendedor.h"
#include "cliente.h"
#include <vector>
#include <string>

class Admin; // Declaração antecipada da classe Admin

class Interface {
private:
    vector<Admin> admins;
    vector<Mecanico> mecanicos;
    vector<Vendedor> vendedores;
    vector<Cliente> clientes;

public:

    Interface();

    void limparTela();
    int interfaceInicial(Interface& sistema);
    int login();
    bool verificarLoginAdmin(const string& nomeUsuario, const string& senha, Interface& sistema);
    bool verificarLoginMecanico(const string& nomeUsuario, const string& senha, Interface& sistema);
    bool verificarLoginVendedor(const string& nomeUsuario, const string& senha, Interface& sistema);
    void iniciarSistema(Interface& sistema);

    // Torna a classe Admin amiga para que ela possa acessar os membros privados
    friend class Admin;
    friend class Vendedor;
};

#endif // INTERFACE_H
