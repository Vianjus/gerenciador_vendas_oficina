#ifndef INTERFACE_H
#define INTERFACE_H

#include "funcionario.h"
#include "admin.h"
#include "mecanico.h"
#include "vendedor.h"
#include "cliente.h"
#include <vector>
#include <string>

class Admin; // Declaração antecipada
class Mecanico;

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
    const vector<Cliente>& getClientes() const { return clientes; }

    // Torna a classes amigas para que elas possam acessar os membros privados
    friend class Admin;
    friend class Vendedor;
    friend class Mecanico;
};

#endif // INTERFACE_H
