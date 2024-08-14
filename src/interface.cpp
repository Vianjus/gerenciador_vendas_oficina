#include "interface.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Interface::Interface() {
    // Inicializando o vetor com um admin padrão
    admins.push_back(Admin("admin", "0", "admin"));
}

void Interface::limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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

bool Interface::verificarLoginAdmin(const string& nomeUsuario, const string& senha) {
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

// Implemente os métodos verificarLoginMecanico e verificarLoginVendedor semelhantes ao verificarLoginAdmin

void Interface::iniciarSistema() {
    int escolha;
    string nomeUsuario, senha;

    do {
        limparTela();
        escolha = interfaceInicial();
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
            // verificarLoginVendedor(nomeUsuario, senha);
            break;

        case 2:
            // verificarLoginMecanico(nomeUsuario, senha);
            break;

        case 3:
            verificarLoginAdmin(nomeUsuario, senha);
            break;
    }
}
