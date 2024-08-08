#include "interface.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void limparTela(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int interfaceInicial (){
  int opcao;
  bool repeat = true;
  do{
  cout << "-- OFICINA DO THOMAS --" << endl << endl
       << "[1] - Login" << endl
       << "[2] - Encerrar" << endl
       << "Selecione uma acima: " << endl;
  cin >> opcao;

  if (opcao == 1 || opcao == 2)
    return (opcao);// Convertendo para inteiro

  limparTela();
  cout << "[!] - Entrada Invalida!" << endl << endl;
  }while(repeat);
  return 2;
}

int login (int escolha){
  bool repeat = true;
  limparTela();
  do{
  cout << "[1] - Vendedor" << endl
       << "[2] - Mecanico" << endl
       << "[3] - Administrador" << endl << endl
       << "Selecione: " << endl;
  cin >> escolha;
  if (escolha == 1 || escolha == 2 || escolha == 3){
    repeat = false;
    break;
  } 
  limparTela();
  cout << "[!] - Entrada Invalida!"<< endl << endl;  
  }while(repeat);

  return escolha;
}