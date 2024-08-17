#include "vendedor.h"
#include "interface.h"
#include "servico.h"

Vendedor::Vendedor(string nome, string cpf, string senha) 
    : Funcionario(nome, cpf, "Vendedor", senha) {}

Vendedor::~Vendedor() {}

void Vendedor::telaInit(Interface& sistema) {
    int option;
    do {
        cout << "========== AREA DO VENDEDOR ==========" << endl
            << "[1] - Cadastrar cliente e veiculo." << endl
            << "[2] - Gerar ordem de servico." << endl
            << "[3] - Visualizar ordens de servico de orcamento pendentes de aprovacao do cliente e marcar como aprovadas." << endl
            << "[4] - Visualizar ordens de servico executadas e realizar o fechamento." << endl
            << "[0] - Voltar\n" << endl;

        cin >> option;

        switch(option) {
            case 0:
                break;
            case 1:
                cadastrarCliente(sistema);
                break;
            case 2:
                gerarOrdem(sistema);
                break;
            case 3:
                visualizarAprovar(sistema);
                break;
            case 4:
                visualizarFechar(sistema);
                break;
            default: 
                cout << "[!] - Entrada invalida\n" << endl;
                break;
        }
    } while (option != 0);
}

void Vendedor::cadastrarCliente(Interface& sistema) {
    string nome;
    string veiculo;

    cout << "Digite o nome do cliente: " << endl;
    cin >> nome; cout << "\n";
    cout << "Digite o modelo do veiculo: " << endl;
    cin >> veiculo; cout << "\n";

    Cliente cliente(nome, veiculo);
    sistema.clientes.push_back(cliente);
}

void Vendedor::gerarOrdem(Interface& sistema) {
    string nome;
    double valorFinal = 0;
    cout << "Digite o nome do cliente: ";
    cin >> nome; cout << "\n";
    cin.ignore();
    
    for (Cliente& meuCliente : sistema.clientes) { // busca o cliente
        if (nome == meuCliente.getNome()) {
            bool repeat;
            do{

                char confirm;
                string nomeServico;
                double valor;
                cout << "CLIENTE: " << meuCliente.getNome() << endl;
                cout << "VEICULO: " << meuCliente.getVeiculo() << endl << endl;
                cout << "Digite nome do servico: ";
                getline(cin, nomeServico);
                cout << "Digite valor do servico: ";
                cin >> valor;
                cin.ignore();
                cout << "\n[!] - Confirma o envio da ordem de servico? [s/n]\n";
                cin >> confirm;
                cin.ignore();
                if(confirm == 'S' ||confirm == 's'){
                    meuCliente.adicionarOrdem(new Servico(nomeServico, valor, 1));
                    cout << "[!] - Ordem aberta com sucesso!\n";
                    valorFinal+= valor;
                }
                else
                    cout << "[!] - Ordem nao aberta!\n";
            
                cout << "\n[!] - Abrir mais ordem de servico? [s/n]\n";
                cin >> confirm;
                cin.ignore();
                repeat = (confirm == 'S' ||confirm == 's') ? true : false;
                    
            } while (repeat);
            cout << "\n[!] - Valor total de todos servicos: " << valorFinal <<endl;
            return;
        }
    }
    cout << "Cliente nao encontrado." << endl;       
}

void Vendedor::visualizarAprovar(Interface& sistema) {
    string nome;
    cout << "Digite o nome do cliente: ";
    cin >> nome; cout << "\n";

    for (Cliente& meuCliente : sistema.clientes) {
        if (meuCliente.getNome() == nome) {
            meuCliente.imprimirOrdensPendentes();
            return;
        }
    }

    cout << "Cliente nao encontrado." << endl;
}

void Vendedor::visualizarFechar(Interface& sistema) {
    string nome;
    cout << "Digite o nome do cliente: ";
    cin >> nome; cout << "\n";

    for (Cliente& meuCliente : sistema.clientes) {
        if (meuCliente.getNome() == nome) {
            meuCliente.imprimirOrdensFinalizadas();
            return;
        }
    }

    cout << "Cliente nao encontrado." << endl;
}
