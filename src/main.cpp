#include <iostream>
#include "interface.h"
using namespace std;

int main() {

  limparTela();
  
  int escolha = interfaceInicial();
  escolha = (escolha == 1) ? login(escolha) : 0;

  limparTela();

  return 0;
};