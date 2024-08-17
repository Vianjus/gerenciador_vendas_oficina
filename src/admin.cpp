#include "admin.h"
#include "interface.h"
#include <iostream>
using namespace std;

//Construtor da classe Admin
Admin::Admin(string nome, string cpf, string senha)
    : Funcionario(nome, cpf, "Admin", senha) {
}

//Destrutor da clase Admin
Admin::~Admin() {}

//Acessa o SistemaAdmin para o admin fazer escolha do que ele quer modificar
void Admin::acessarSistemaAdmin(Interface& sistema) const {
    int escolha;
    do
    { 
        cout << "Acesso concedido!" << endl << endl;
        escolha = telaAdmin();

        switch (escolha)
        {
        case 1: //Vendedor
            modificarVendedor(sistema);
            break;
        
        case 2: //Mecânico
            modificarMecanico(sistema);
            break;

        case 3: //Admin
            modificarAdmin(sistema);
            break;
        default:
            break;
        }
    } while (escolha != 0);    
}

//Tela que aparece para o Admin escolher o que ele quer fazer
int Admin::telaAdmin() const {

    int escolha;
    cout << "[1] - Vendedores" << endl
         << "[2] - Mecanicos" << endl
         << "[3] - Administrador" << endl << endl
         << "[0] - Voltar" << endl
         << "Selecione qual cargo desejada modificar: " << endl;
    do{
    cin >> escolha;
    cin.ignore(); // Limpa o buffer do cin
    if (escolha >= 0 && escolha <= 3)
        return escolha;
    cout << "[!] - Entrada incorreta" << endl
         << "Digite novamente: ";
    }while (true);
    
}

//Tela das opções do que se pode fazer com os dados de um vendedor
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
        cin.ignore(); // Limpa o buffer do cin

        switch (escolha)
        {
        case 0:
            
            break;
        
        case 1:
            adicionarVendedor(sistema);
            break;

        case 2:
            editarVendedor(sistema);
            break;

        case 3:
            excluirVendedor(sistema);
            break;
        
        default:
            cout << "[!] - Valor invalido" << endl;
            break;
        }
    } while (escolha != 0);
}

//Tela das opções do que se pode fazer com os dados de um mecanico
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
        cin.ignore(); // Limpa o buffer do cin

        switch (escolha)
        {
        case 0:
            
            break;
        
        case 1:
            adicionarMecanico(sistema);
            break;

        case 2:
            editarMecanico(sistema);
            break;

        case 3:
            excluirMecanico(sistema);
            break;
        
        default:
            cout << "[!] - Valor invalido" << endl;
            break;
        }
    } while (escolha != 0);
}

//Tela das opções do que se pode fazer com os dados de um admin
void Admin::modificarAdmin(Interface& sistema) const {

    int escolha;
    do{
        cout << "--Area do Administrador--" << endl << endl
            << "[1] - Editar os dados do administrador" << endl
            << "[0] - Voltar" << endl << endl
            << "Selecione: ";
        cin >> escolha;
        cin.ignore(); // Limpa o buffer do cin

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

//Modifica dados de um admin ja existente
void Admin:: editarAdmin(Interface& sistema) const {
    string nome, cpf, senha;
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

//Adciona um mecanico
void Admin::adicionarMecanico(Interface& sistema) const {
    string nome, cpf, senha;
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

//Adiciona um vendedor
void Admin::adicionarVendedor(Interface& sistema) const {
    string nome, cpf, senha;
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

//Modifica dados de um vendedor ja existente
void Admin::editarVendedor(Interface& sistema) const {
    string nomeBusca;
    
    cout << "Digite o nome de quem voce quer editar: " << endl;
    getline(cin, nomeBusca);

    for (auto& Vendedor : sistema.vendedores) {
        if (Vendedor.getNome() == nomeBusca) {
            cout << "\nDados da pessoa encontrada!" << endl << endl;
            Vendedor.printInfo();

            char escolha;
            cout << "Deseja editar os dados dessa pessoa? (s/n): ";
            cin >> escolha;

            if (escolha == 's' || escolha == 'S') {
                string novoNome, novoCpf, novaSenha;
                cout << "Digite o novo nome: ";
                cin.ignore(); // Limpa o buffer do cin
                getline(cin, novoNome);
                cout << "Digite o novo CPF: ";
                getline(cin, novoCpf);
                cout << "Digite a nova senha: ";
                getline(cin, novaSenha);

                Vendedor.setNome(novoNome);
                Vendedor.setCpf(novoCpf);
                Vendedor.setSenha(novaSenha);

                cout << "Dados atualizados com sucesso!" << endl;
            }
            return;
        }
    }
    cout << "\nPessoa nao encontrada." << endl << endl;
}

//Modifica dados de um mecanico ja existente
void Admin::editarMecanico(Interface& sistema) const {
    string nomeBusca;
    
    cout << "Digite o nome de quem voce quer editar: " << endl;
    getline(cin, nomeBusca);

    for (auto& Mecanico : sistema.mecanicos) {
        if (Mecanico.getNome() == nomeBusca) {
            cout << "\nDados da pessoa encontrada!" << endl << endl;
            Mecanico.printInfo();

            char escolha;
            cout << "Deseja editar os dados dessa pessoa? (s/n): ";
            cin >> escolha;

            if (escolha == 's' || escolha == 'S') {
                string novoNome, novoCpf, novaSenha;
                cout << "Digite o novo nome: ";
                cin.ignore(); // Limpa o buffer do cin
                getline(cin, novoNome);
                cout << "Digite o novo CPF: ";
                getline(cin, novoCpf);
                cout << "Digite a nova senha: ";
                getline(cin, novaSenha);

                Mecanico.setNome(novoNome);
                Mecanico.setCpf(novoCpf);
                Mecanico.setSenha(novaSenha);

                cout << "Dados atualizados com sucesso!" << endl;
            }
            return;
        }
    }
    cout << "\nPessoa nao encontrada." << endl << endl;
}

//Exclui dados de um vendedor ja existente
void Admin::excluirVendedor(Interface& sistema) const {
    string nomeBusca;
    
    cout << "Digite o nome de quem voce quer excluir: " << endl;
    getline(cin, nomeBusca);

    for (auto it = sistema.vendedores.begin(); it != sistema.vendedores.end(); ++it) {
        if (it->getNome() == nomeBusca) {
            cout << "\nDados do vendedor encontrado!" << endl << endl;
            it->printInfo();

            char escolha;
            cout << "Deseja excluir os dados desse vendedor? (s/n): ";
            cin >> escolha;

            if (escolha == 's' || escolha == 'S') {
                sistema.vendedores.erase(it);
                cout << "Vendedor excluido com sucesso!" << endl;
            } else {
                cout << "Operacao cancelada." << endl;
            }
            return;
        }
    }

    cout << "Vendedor nao encontrado." << endl;
}

//Exclui dados de um mecanico ja existente
void Admin::excluirMecanico(Interface& sistema) const {
    string nomeBusca;
    
    cout << "Digite o nome do mecanico que você quer excluir: ";
    getline(cin, nomeBusca);

    for (auto it = sistema.mecanicos.begin(); it != sistema.mecanicos.end(); ++it) {
        if (it->getNome() == nomeBusca) {
            cout << "\nDados do mecanico encontrado!" << endl << endl;
            it->printInfo();

            char escolha;
            cout << "Deseja excluir os dados desse mecanico? (s/n): ";
            cin >> escolha;

            if (escolha == 's' || escolha == 'S') {
                sistema.mecanicos.erase(it);
                cout << "Mecanico excluído com sucesso." << endl;
            } else {
                cout << "Exclusao cancelada." << endl;
            }
            return;
        }
    }

    cout << "Mecanico nao encontrado." << endl;
}
