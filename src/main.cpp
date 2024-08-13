#include <iostream>
#include "interface.h"
#include "admin.h"
#include "vendedor.h"
#include "mecanico.h"
#include <vector>

using namespace std;

int main() {

  int escolha;
  vector<Admin> admins;
  admins.push_back(Admin ("admin", "0", "admin"));
  vector<Mecanico> mecanicos;
  vector<Vendedor> vendedores;
  string nomeUsuario, senha;

  do
  {
  limparTela();
  
  escolha = interfaceInicial();
  if(escolha == 2)
    return 0;
  escolha = login(escolha);
  } while (escolha == 0);
  
  getchar();
  cout << "Digite o nome de usuario: ";
  getline(cin, nomeUsuario);

  cout << "Digite a senha: ";
  getline(cin, senha);
  
  switch (escolha) {
    case 1:
      //verificarLoginVend(vendedores, nomeUsuario, senha);  
      break;

    case 2:
      //verificarLoginMec(mecanicos, nomeUsuario, senha);
      break;

    case 3:
      verificarLoginAdmin(admins, nomeUsuario, senha);  
      break;
    };
  

  //limparTela();

  return 0;
};