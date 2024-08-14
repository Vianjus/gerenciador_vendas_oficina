#ifndef INTERFACE_H
#define INTERFACE_H

#include "funcionario.h"
#include "admin.h"
#include "mecanico.h"
#include "vendedor.h"
#include <vector>
#include <string>

class Interface {
private:
    vector<Admin> admins;
    vector<Mecanico> mecanicos;
    vector<Vendedor> vendedores;

public:
    Interface();

    void limparTela();
    int interfaceInicial();
    int login();
    bool verificarLoginAdmin(const string& nomeUsuario, const string& senha);
    // Adicione métodos para verificar login de Mecânico e Vendedor
    // bool verificarLoginMecanico(const string& nomeUsuario, const string& senha);
    // bool verificarLoginVendedor(const string& nomeUsuario, const string& senha);
    void iniciarSistema();
};

#endif // INTERFACE_H
