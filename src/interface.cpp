#include "interface.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "vendedor.h"
#include "mecanico.h"
#include "funcionario.h"

using namespace std;

void limparTela(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool arquivoExiste(const string& nome){
  ifstream arquivo(nome);
  return arquivo.good();
}

int interfaceInicial (){
  int opcao;
  bool repeat = true;
  do{
  cout << "-- OFICINA DO THOMAS --" << endl << endl
       << "[1] - Login" << endl
       << "[2] - Encerrar" << endl
       << "Selecione uma acima: " << endl;
  cin >> opcao;

  if (opcao == 1 || opcao == 2)
    return (opcao);// Convertendo para inteiro

  limparTela();
  cout << "[!] - Entrada Invalida!" << endl << endl;
  }while(repeat);
  return 2;
}

int login (int escolha){
  bool repeat = true;
  limparTela();
  do{
  cout << "[1] - Vendedor" << endl
       << "[2] - Mecanico" << endl
       << "[3] - Administrador" << endl << endl
       << "Selecione: " << endl;
  cin >> escolha;
  if (escolha == 1 || escolha == 2 || escolha == 3){
    repeat = false;
    break;
  } 
  limparTela();
  cout << "[!] - Entrada Invalida!"<< endl << endl;  
  }while(repeat);

  return escolha;
}

bool interfaceLogin(int tipoDeUsuario) {
  string inputUser, inputPassword;
  string user, password;
  string nomeArquivo;
  bool sucesso = false;
  limparTela();

  switch (tipoDeUsuario)
  {
  case 1:
  case 2:
    nomeArquivo = "data/usuarios/";
    break;
  case 3:
    nomeArquivo = "data/usuarios/administrador/";
    break;
  }

  bool repeat = true;
  do{
    cout << "usuario: ";
    cin >> inputUser;

    cout << "senha: ";
    cin >> inputPassword;

    nomeArquivo+=inputUser + ".txt";


    if(!arquivoExiste(nomeArquivo)){
      limparTela();
      cerr << "Erro usuario nao encontrado: " << user << endl;
      cout << "Tente novamente!" << endl << endl;
      break;
    }
    ifstream arquivo(nomeArquivo);

    getline(arquivo, user);
    getline(arquivo, password);

    if (inputUser == user && inputPassword == password) {
      sucesso = true;
      repeat = false;
      break;
    } else {
      limparTela();
      cout << "Nome de usuario ou senha incorreto!" << endl;
    }

    if(!sucesso){
      cout << "Nome de usuario ou senha incorretos!" << endl
          << "Tente Novamente!" << endl << endl;
    }
  }while(repeat);

  return sucesso;
}

int interfaceVendedor() {
  int escolha = 0;
  bool repeat = true;
  limparTela();
  do{
    cout << "-- AREA DO VENDEDOR --" << endl
         << "[1] - Cadastrar cliente" << endl
         << "[2] - Cadastrar veiculo" << endl
         << "[3] - Gerar ordem de servico" << endl
         << "[4] - Visualizar ordens de servico pendentes" << endl
         << "[5] - Visualizar ordens de servico executadas" << endl << endl
         << "Selecione: " << endl;
    cin >> escolha;
    if(escolha > 0 && escolha <= 5){
      repeat = false;
      break;
    }
    limparTela();
    cout << "[!] - Entrada Invalida!"<< endl << endl;  
  }while(repeat);
  return escolha;
}

int interfaceAdministrador(){
  bool repeat = true;
  int opcao = 0;
  limparTela();
  do{
    cout << "-- AREA DO ADMINISTRADOR --" << endl
         << "[1] - Adicionar Funcionario" << endl
         << "[2] - Editar Funcionario" << endl << endl
         << "[3] - Excluir Funcionario" << endl << endl
         << "Selecione: " << endl;
    cin >> opcao;
    if(opcao == 1 || opcao == 2 || opcao == 3){
      repeat = false;
      break;
    }
    limparTela();
    cout << "[!] - Entrada Invalida!"<< endl << endl;  
  }while(repeat);
  return opcao;
}


void salvarFuncionario(Funcionario& funcionario){
  string nomeArquivo = "data/usuarios/" + funcionario.getCpf() + ".txt";
  ofstream arquivo(nomeArquivo);

  if(!arquivo){
    std::cout << "Erro ao abrir arquivo para escrita!!" << endl;
    return;
  }

  arquivo << funcionario.getCpf() << endl
          << funcionario.getSenha() << endl
          << funcionario.getNome() << endl
          << funcionario.getCargo() << endl;

  arquivo.close();
}

void adicionarFuncionario(){
  limparTela();
  bool repeat = true;
  char confirmacao;
  int cargo;
  string nome, cpf, senha;

  do{
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
    if(confirmacao == 's' && (cargo == 1 || cargo == 2)){
      repeat = false;
      break;
    } else if(cargo != 1 && cargo != 2){
      limparTela();
      cout << "Cargo Inexistente!" << endl
           << "Digite os dados novamente" << endl << endl;
    }
  }while(repeat);


  if(arquivoExiste("data/usuarios/" + cpf + ".txt")){
    cout << "Funcionario ja existe!" << endl;
  }else {
    Funcionario* novoFuncionario;
    if(cargo == 1){
      novoFuncionario = new Vendedor(nome, cpf, senha);
    } else {
      novoFuncionario = new Mecanico(nome, cpf, senha);
    }
    salvarFuncionario(*novoFuncionario);
    delete novoFuncionario;
  }
}