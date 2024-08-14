#include "interface.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

Interface::Interface() {}
Interface::~Interface() {}

void Interface::limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool Interface::arquivoExiste(const string& nome) {
    ifstream arquivo(nome);
    return arquivo.good();
}

int Interface::interfaceInicial() {
    int opcao;
    bool repeat = true;
    do {
        cout << "-- OFICINA DO THOMAS --" << endl << endl
             << "[1] - Login" << endl
             << "[2] - Encerrar" << endl
             << "Selecione uma acima: " << endl;
        cin >> opcao;

        if (opcao == 1 || opcao == 2)
            return opcao;

        limparTela();
        cout << "[!] - Entrada Invalida!" << endl << endl;
    } while (repeat);
    return 2;
}

int Interface::login() {
    int escolha;
    bool repeat = true;
    limparTela();
    do {
        cout << "[0] - Voltar" << endl
             << "[1] - Vendedor" << endl
             << "[2] - Mecanico" << endl
             << "[3] - Administrador" << endl << endl
             << "Selecione: " << endl;
        cin >> escolha;
        if (escolha >= 0 && escolha <= 3) {
            repeat = false;
            break;
        } 
        limparTela();
        cout << "[!] - Entrada Invalida!" << endl << endl;  
    } while (repeat);

    return escolha;
}

bool Interface::interfaceLogin(int tipoDeUsuario, const vector<Admin>& admins, const vector<Mecanico>& mecanicos, const vector<Vendedor>& vendedores) {
    string inputUser, inputPassword;
    string nomeArquivo;
    bool sucesso = false;
    limparTela();

    switch (tipoDeUsuario) {
    case 1:
    case 2:
        nomeArquivo = "data/usuarios/";
        break;
    case 3:
        nomeArquivo = "data/usuarios/administrador/";
        break;
    }

    bool repeat = true;
    do {
        cout << "Usuario: ";
        cin >> inputUser;

        cout << "Senha: ";
        cin >> inputPassword;

        nomeArquivo += inputUser + ".txt";

        if (!arquivoExiste(nomeArquivo)) {
            limparTela();
            cerr << "Erro usuario nao encontrado: " << inputUser << endl;
            cout << "Tente novamente!" << endl << endl;
            break;
        }
        ifstream arquivo(nomeArquivo);
        string user, password;
        getline(arquivo, user);
        getline(arquivo, password);

        if (inputUser == user && inputPassword == password) {
            sucesso = true;
            repeat = false;
        } else {
            limparTela();
            cout << "Nome de usuario ou senha incorreto!" << endl;
        }

        if (!sucesso) {
            cout << "Nome de usuario ou senha incorretos!" << endl
                 << "Tente Novamente!" << endl << endl;
        }
    } while (repeat);

    return sucesso;
}

bool Interface::verificarLoginAdmin(const vector<Admin>& admins, const string& nomeUsuario, const string& senha) {
    for (const auto& admin : admins) {
        if (admin.getNome() == nomeUsuario) {
            if (admin.getSenha() == senha) {
                admin.acessarSistemaAdmin();
                return true;
            } else {
                cout << "Senha incorreta!" << endl;
                return false;
            }
        }
    }
    cout << "Usuario nao existe!" << endl;
    return false;
}

int Interface::interfaceVendedor() {
    int escolha = 0;
    bool repeat = true;
    limparTela();
    do {
        cout << "-- AREA DO VENDEDOR --" << endl
             << "[1] - Cadastrar cliente" << endl
             << "[2] - Cadastrar veiculo" << endl
             << "[3] - Gerar ordem de servico" << endl
             << "[4] - Visualizar ordens de servico pendentes" << endl
             << "[5] - Visualizar ordens de servico executadas" << endl << endl
             << "Selecione: " << endl;
        cin >> escolha;
        if (escolha > 0 && escolha <= 5) {
            repeat = false;
            break;
        }
        limparTela();
        cout << "[!] - Entrada Invalida!" << endl << endl;  
    } while (repeat);
    return escolha;
}

int Interface::interfaceAdministrador() {
    bool repeat = true;
    int opcao = 0;
    limparTela();
    do {
        cout << "-- AREA DO ADMINISTRADOR --" << endl
             << "[1] - Adicionar Funcionario" << endl
             << "[2] - Editar Funcionario" << endl
             << "[3] - Excluir Funcionario" << endl << endl
             << "Selecione: " << endl;
        cin >> opcao;
        if (opcao == 1 || opcao == 2 || opcao == 3) {
            repeat = false;
            break;
        }
        limparTela();
        cout << "[!] - Entrada Invalida!" << endl << endl;  
    } while (repeat);
    return opcao;
}

void Interface::salvarFuncionario(const Funcionario& funcionario) {
    string nomeArquivo = "data/usuarios/" + funcionario.getCpf() + ".txt";
    ofstream arquivo(nomeArquivo);

    if (!arquivo) {
        cout << "Erro ao abrir arquivo para escrita!!" << endl;
        return;
    }

    arquivo << funcionario.getCpf() << endl
            << funcionario.getSenha() << endl
            << funcionario.getNome() << endl
            << funcionario.getCargo() << endl;

    arquivo.close();
}

void Interface::adicionarFuncionario(vector<Vendedor>& vendedores, vector<Mecanico>& mecanicos) {
    limparTela();
    bool repeat = true;
    char confirmacao;
    int cargo;
    string nome, cpf, senha;

    do {
        cout << "Nome: ";
        cin >> nome;
        cout << "CPF: ";
        cin >> cpf;
        cout << "Selecione o cargo deste funcionario: " << endl
             << "[1] - Vendedor" << endl
             << "[2] - Mecanico" << endl;
        cout << "Cargo: ";
        cin >> cargo;
        cout << "senha: ";
        cin >> senha;
        cout << endl << "Voce confirma que os dados estao corretos? (s/n)" << endl;
        cin >> confirmacao;
        if (confirmacao == 's' && (cargo == 1 || cargo == 2)) {
            repeat = false;
            break;
        } else if (cargo != 1 && cargo != 2) {
            limparTela();
            cout << "Cargo Inexistente!" << endl
                 << "Digite os dados novamente" << endl << endl;
        }
    } while (repeat);

    if (arquivoExiste("data/usuarios/" + cpf + ".txt")) {
        cout << "Funcionario ja existe!" << endl;
    } else {
        if (cargo == 1) {
            Vendedor vendedor(nome, cpf, senha);
            vendedores.push_back(vendedor);
            salvarFuncionario(vendedor);
        } else {
            Mecanico mecanico(nome, cpf, senha);
            mecanicos.push_back(mecanico);
            salvarFuncionario(mecanico);
        }
    }
}
