#include <iostream>
#include <vector>
#include "interface.h"

using namespace std;

int main() {
    Interface sistema;
    int escolha;
    vector<Admin> admins;
    admins.push_back(Admin("admin", "0", "admin"));
    vector<Mecanico> mecanicos;
    vector<Vendedor> vendedores;
    string nomeUsuario, senha;

    do {
        sistema.limparTela();

        escolha = sistema.interfaceInicial();
        if (escolha == 2)
            return 0;

        escolha = sistema.login();
    } while (escolha == 0);

    getchar();  // Para capturar o enter após a escolha
    cout << "Digite o nome de usuario: ";
    getline(cin, nomeUsuario);

    cout << "Digite a senha: ";
    getline(cin, senha);
  
    switch (escolha) {
        case 1:
            // Aqui você chamaria uma função para verificar o login de Vendedor
            // ex: interface.verificarLoginVendedor(vendedores, nomeUsuario, senha);
            break;

        case 2:
            // Aqui você chamaria uma função para verificar o login de Mecânico
            // ex: interface.verificarLoginMecanico(mecanicos, nomeUsuario, senha);
            break;

        case 3:
            sistema.verificarLoginAdmin(admins, nomeUsuario, senha);
            break;
    }

    return 0;
}
