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
       << "[1] - Visualizar ordens de servico abertas" << endl
       << "[2] - Cadastrar servicos executados e pecas utilizadas" << endl
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
    cout << "\n[!] - Entrada Invalida\n"<< endl;
    break;
  }
  }while(escolha != 0);

}

void Mecanico::imprimirOrdensPendentes(Interface& sistema){
    const vector<Cliente>& clientes = sistema.getClientes();
    for (const Cliente& cliente : clientes) {
        cout << "Cliente: " << cliente.getNome() << " - Veiculo: " << cliente.getVeiculo() << endl;
        cliente.imprimirOrdensPendentes();
        cout << "-------------------------" << endl;
    }
}

void Mecanico::finalizarOrdem(Interface& sistema) const {
    string nomeCliente;
    size_t ordemIndex = -1;

    cout << "Digite o nome do cliente: ";
    getline(cin, nomeCliente);

    for (Cliente& cliente : sistema.clientes) {
        if (cliente.getNome() == nomeCliente) {
            cliente.imprimirOrdensPendentes(); // Imprime as ordens pendentes

            cout << "Digite o indice da ordem de servico que deseja finalizar: ";
            cin >> ordemIndex;
            cin.ignore(); // Para limpar o buffer após a leitura do índice

            if (ordemIndex >= 0 && ordemIndex < cliente.getOrdens().size()) {
                Servico* servico = cliente.getOrdens()[ordemIndex];
                if (servico->isPendente()) {
                    servico->marcarComoFinalizado();
                    cout << "Ordem de servico finalizada com sucesso!" << endl;
                } else {
                    cout << "A ordem de servico nao esta pendente." << endl;
                }
            } else {
                cout << "Indice invalido." << endl;
            }
            return;
        }
    }

    cout << "Cliente nao encontrado." << endl;
}