#include <iostream>
#include "interface.h"
using namespace std;

int main() {

  limparTela();
  
  int escolha = interfaceInicial();
  escolha = (escolha == 1) ? login(escolha) : 0;
  if(escolha != 0 && interfaceLogin(escolha)){
    switch (escolha) {
      case 1:
        escolha = interfaceVendedor();
      break;
      case 2:
        //adicionar interface do mecanico
      break;

      case 3:
        escolha = interfaceAdministrador();
        if(escolha == 1){
          adicionarFuncionario();
        } else {

        }
        break;
    }
  }

  limparTela();

  return 0;
};