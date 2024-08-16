#include "interface.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Interface::Interface() {
    // Inicializando os vetores
    admins.push_back(Admin("admin", "0", "admin"));
    mecanicos.push_back(Mecanico("mecanico", "0", "admin"));
    vendedores.push_back(Vendedor("vendedor", "0", "admin"));
}

void Interface::limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int Interface::interfaceInicial(Interface& sistema) {
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

void Interface::iniciarSistema(Interface& sistema) {
    int escolha;
    string nomeUsuario, senha;
    bool sucess;

    do{
        do {
            limparTela();
            escolha = interfaceInicial(sistema);
            if (escolha == 2)
                return;

            escolha = login();
        } while (escolha == 0);

        getchar();  // Para capturar o enter após a escolha
        cout << "Digite o nome de usuario: ";
        getline(cin, nomeUsuario);

        cout << "Digite a senha: ";
        getline(cin, senha);

        switch (escolha) {
            case 1:
                sucess = verificarLoginVendedor(nomeUsuario, senha, sistema);
                break;

            case 2:
                sucess = verificarLoginMecanico(nomeUsuario, senha, sistema);
                break;

            case 3:
                sucess = verificarLoginAdmin(nomeUsuario, senha, sistema);
                break;
        }
    if (sucess == false)
    {
        cout << "Enter para tentar novamente" << endl;
        getline(cin, nomeUsuario);
    }
    
    }while(escolha != 2);
}

bool Interface::verificarLoginAdmin(const string& nomeUsuario, const string& senha, Interface& sistema) {
    for (const auto& admin : admins) {
        if (admin.getNome() == nomeUsuario) {
            if (admin.getSenha() == senha) {
                limparTela();
                admin.acessarSistemaAdmin(sistema);
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

bool Interface::verificarLoginVendedor(const string& nomeUsuario, const string& senha, Interface& sistema) {
    string aux; //só para verificar se esta acessando EXCLUIR DPS
    for (const auto& vendedor : vendedores) {
        if (vendedor.getNome() == nomeUsuario) {
            if (vendedor.getSenha() == senha) {
                limparTela();
                cout << "Login de Vendedor bem-sucedido!" << endl;
                vendedor.telaInit(sistema);
                return true;
            } else {
                cout << "Senha incorreta!" << endl;
                getline(cin, aux);
                return false;
            }
        }
    }
    cout << "Usuario nao existe!" << endl;
    return false;
}

bool Interface::verificarLoginMecanico(const string& nomeUsuario, const string& senha, Interface& sistema) {
    for (const auto& mecanico : mecanicos) {
        if (mecanico.getNome() == nomeUsuario) {
            if (mecanico.getSenha() == senha) {
                limparTela();
                cout << "Login de Mecanico bem-sucedido!" << endl;
                // Adicione aqui o código para acessar o sistema de mecânico
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

