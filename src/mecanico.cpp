#include "mecanico.h"
#include "interface.h"
#include <iostream>
using namespace std;

Mecanico::Mecanico(string nome, string cpf, string senha) : Funcionario(nome, cpf, "Mecanico", senha) {}

Mecanico::~Mecanico() {}

void Mecanico::acessarSistemaMecanico(Interface& sistema){

  int escolha;

  do{
  cout << "--AREA DO MECANICO--\n" << endl
       << "[1] - Visualizar ordens de serviço abertas" << endl
       << "[2] - Cadastrar serviços executados e peças utilizadas" << endl
       << "[0] - Voltar\n" << endl
       << "Selecione: ";
  cin >> escolha;
  cin.ignore();

  switch (escolha)
  {
  case 0:// voltar
    
    break;

  case 1:
    imprimirOrdensPendentes(sistema);
    break;

  case 2:
    finalizarOrdem(sistema);
    break;

  default:
    cout << "\n[!] - Entrada Inválida\n"<< endl;
    break;
  }
  }while(escolha != 0);

}

void Mecanico::imprimirOrdensPendentes(Interface& sistema){
    const vector<Cliente>& clientes = sistema.getClientes();
    for (const Cliente& cliente : clientes) {
        cout << "Cliente: " << cliente.getNome() << " - Veículo: " << cliente.getVeiculo() << endl;
        cliente.imprimirOrdensPendentes();
        cout << "-------------------------" << endl;
    }
}

void Mecanico::finalizarOrdem(Interface& sistema) const {
    string nomeCliente;
    int ordemIndex = -1;

    cout << "Digite o nome do cliente: ";
    getline(cin, nomeCliente);

    for (Cliente& cliente : sistema.clientes) {
        if (cliente.getNome() == nomeCliente) {
            cliente.imprimirOrdensPendentes(); // Imprime as ordens pendentes

            cout << "Digite o índice da ordem de serviço que deseja finalizar: ";
            cin >> ordemIndex;
            cin.ignore(); // Para limpar o buffer após a leitura do índice

            if (ordemIndex >= 0 && ordemIndex < cliente.getOrdens().size()) {
                Servico* servico = cliente.getOrdens()[ordemIndex];
                if (servico->isPendente()) {
                    servico->marcarComoFinalizado();
                    cout << "Ordem de serviço finalizada com sucesso!" << endl;
                } else {
                    cout << "A ordem de serviço não está pendente." << endl;
                }
            } else {
                cout << "Índice inválido." << endl;
            }
            return;
        }
    }

    cout << "Cliente não encontrado." << endl;
}