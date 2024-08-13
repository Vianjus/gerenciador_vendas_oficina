#ifndef INTERFACE_H
#define INTERFACE_H

using namespace std;

#include "funcionario.h"
#include "admin.h"
#include <vector>

void limparTela();
bool arquivoExiste(const string&);

int interfaceInicial();
int login(int);

bool interfaceLogin(int);
bool verificarLoginAdmin(const vector<Admin>&, const string&, const string&);
int interfaceVendedor();
int interfaceAdministrador();

void adicionarFuncionario();
void salvarFuncionario(Funcionario&);

#endif // INTERFACE_H
