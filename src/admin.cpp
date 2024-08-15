#include "admin.h"
#include "interface.h"
#include <iostream>
using namespace std;

Admin::Admin(string nome, string cpf, string senha)
    : Funcionario(nome, cpf, "Admin", senha) {
}

Admin::~Admin() {}

void Admin::acessarSistemaAdmin(Interface& sistema) const {
    int escolha;
    do
    { 
        cout << "Acesso concedido: " << nome << endl << endl;
        escolha = telaAdmin();

        switch (escolha)
        {
        case 1: //Vendedor
            modificarVendedor(sistema);
            break;
        
        case 2: //Mecânico
            
            break;

        case 3: //Admin
            modificarAdmin(sistema);
            break;
        default:
            break;
        }
    } while (escolha != 0);    
}

int Admin::telaAdmin() const {

    int escolha;
    cout << "[1] - Vendedores" << endl
         << "[2] - Mecanicos" << endl
         << "[3] - Administrador" << endl << endl
         << "[0] - Voltar" << endl
         << "Selecione qual cargo desejada modificar: " << endl;
    do{
    cin >> escolha;
    if (escolha >= 0 && escolha <= 3)
        return escolha;
    cout << "[!] - Entrada incorreta" << endl
         << "Digite novamente: ";
    }while (true);
    
}

void Admin::modificarVendedor(Interface& sistema) const {

    int escolha;
    do{
        cout << "--Area dos Vendedores--" << endl << endl
            << "[1] - Adicionar novo vendedor" << endl
            << "[2] - Editar um vendedor existente" << endl
            << "[3] - Excluir um vendedor existente" << endl << endl
            << "[0] - Voltar" << endl << endl
            << "Selecione: ";
        cin >> escolha;

        switch (escolha)
        {
        case 0:
            
            break;
        
        case 1:
            adicionarVendedor(sistema);
            break;

        case 2:
            
            break;

        case 3:
            
            break;
        
        default:
            cout << "[!] - Valor invalido" << endl;
            break;
        }
    } while (escolha != 0);
}

void Admin::modificarMecanico(Interface& sistema) const {

    int escolha;
    do{
        cout << "--Area dos Mecanicos--" << endl << endl
            << "[1] - Adicionar novo mecanico" << endl
            << "[2] - Editar um mecanico existente" << endl
            << "[3] - Excluir um mecanico existente" << endl << endl
            << "[0] - Voltar" << endl << endl
            << "Selecione: ";
        cin >> escolha;

        switch (escolha)
        {
        case 0:
            
            break;
        
        case 1:
            adicionarMecanico(sistema);
            break;

        case 2:
            
            break;

        case 3:
            
            break;
        
        default:
            cout << "[!] - Valor invalido" << endl;
            break;
        }
    } while (escolha != 0);
}

void Admin::modificarAdmin(Interface& sistema) const {

    int escolha;
    do{
        cout << "--Area do Administrador--" << endl << endl
            << "[1] - Editar os dados do administrador" << endl
            << "[0] - Voltar" << endl << endl
            << "Selecione: ";
        cin >> escolha;

        switch (escolha)
        {
        case 0:
            
            break;
        
        case 1:
            editarAdmin(sistema);
            break;
        
        default:
            cout << "[!] - Valor invalido" << endl;
            break;
        }
    } while (escolha != 0);
}

void Admin:: editarAdmin(Interface& sistema) const {
    string nome, cpf, senha;
    getchar();
    cout << "Digite o novo nome:" << endl;
    getline( cin, nome);
    cout << "Digite o novo cpf:" << endl;
    getline( cin, cpf);
    cout << "Digite a nova senha:" << endl;
    getline( cin, senha);
    Admin novoAdmin(nome, cpf, senha);
    sistema.admins.push_back(novoAdmin);
    sistema.admins.erase(sistema.admins.begin());
    cout << "Administrador atualizado com sucesso!\n";
}

void Admin::adicionarMecanico(Interface& sistema) const {
    string nome, cpf, senha;
    getchar();
    cout << "Digite o nome do novo mecanico:" << endl;
    getline( cin, nome);
    cout << "Digite o cpf do novo mecanico:" << endl;
    getline( cin, cpf);
    cout << "Digite a senha do novo mecanico:" << endl;
    getline( cin, senha);
    Mecanico novoMecanico(nome, cpf, senha);
    sistema.mecanicos.push_back(novoMecanico);
    cout << "Mecanico adicionado com sucesso!\n";
}

void Admin::adicionarVendedor(Interface& sistema) const {
    string nome, cpf, senha;
    getchar();
    cout << "Digite o nome do novo vendedor:" << endl;
    getline( cin, nome);
    cout << "Digite o cpf do novo vendedor:" << endl;
    getline( cin, cpf);
    cout << "Digite a senha do novo vendedor:" << endl;
    getline( cin, senha);
    Vendedor novoVendedor(nome, cpf, senha);
    sistema.vendedores.push_back(novoVendedor);
    cout << "Vendedor adicionado com sucesso!\n";
}

// void Admin::editarVendedor(Interface& sistema) const {
//     for (auto& sistema.vendedores : pessoas) {
//         if (pessoa.getNome() == nomeBusca) {
//             cout << "Dados da pessoa encontrada:" << endl;
//             pessoa.printInfo();

//             char escolha;
//             cout << "Deseja editar os dados dessa pessoa? (s/n): ";
//             cin >> escolha;

//             if (escolha == 's' || escolha == 'S') {
//                 string novoNome, novoCpf, novaSenha;
//                 cout << "Digite o novo nome: ";
//                 cin.ignore(); // Limpa o buffer do cin
//                 getline(cin, novoNome);
//                 cout << "Digite o novo CPF: ";
//                 getline(cin, novoCpf);
//                 cout << "Digite a nova senha: ";
//                 getline(cin, novaSenha);

//                 pessoa.setNome(novoNome);
//                 pessoa.setCpf(novoCpf);
//                 pessoa.setSenha(novaSenha);

//                 cout << "Dados atualizados com sucesso!" << endl;
//             }
//             return;
//         }
//     }
//     cout << "Pessoa não encontrada." << endl;
// }