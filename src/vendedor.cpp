#include "vendedor.h"
#include "interface.h"

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
    cout << "Digite o nome do cliente: ";
    cin >> nome; cout << "\n";
    
    for (Cliente& meuCliente : sistema.clientes) { // busca o cliente
        if (nome == meuCliente.getNome()) {
            cout << "CLIENTE: " << meuCliente.getNome() << endl;
            cout << "VEICULO: " << meuCliente.getVeiculo() << endl;

            int servico = rand()%2 + 1;
            int valor = (servico == 1) ? 100 : 1000;

            meuCliente.adicionarOrdem(new Servico("Descricao do servico", valor, servico));
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
