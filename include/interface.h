#ifndef INTERFACE_H
#define INTERFACE_H

#include "funcionario.h"

void limparTela();
bool arquivoExiste(const std::string&);

int interfaceInicial();
int login(int);

bool interfaceLogin(int);
int interfaceVendedor();
int interfaceAdministrador();

void adicionarFuncionario();
void salvarFuncionario(Funcionario&);

#endif // INTERFACE_H
