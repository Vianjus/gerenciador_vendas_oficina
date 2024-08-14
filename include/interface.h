#ifndef INTERFACE_H
#define INTERFACE_H

#include "funcionario.h"
#include "admin.h"
#include "mecanico.h"
#include "vendedor.h"
#include <vector>
#include <string>

using namespace std;

class Interface {
public:
    Interface();
    ~Interface();

    void limparTela();
    bool arquivoExiste(const string& nome);
    int interfaceInicial();
    int login();
    bool interfaceLogin(int tipoDeUsuario, const vector<Admin>& admins, const vector<Mecanico>& mecanicos, const vector<Vendedor>& vendedores);
    bool verificarLoginAdmin(const vector<Admin>& admins, const string& nomeUsuario, const string& senha);
    int interfaceVendedor();
    int interfaceAdministrador();
    void adicionarFuncionario(vector<Vendedor>& vendedores, vector<Mecanico>& mecanicos);
    void salvarFuncionario(const Funcionario& funcionario);
};

#endif // INTERFACE_H
