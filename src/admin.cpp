#include <iostream>
#include "admin.h"
using namespace std;


// Construtor da classe Admin
Admin::Admin(string nome, string cpf, string senha)
    : Funcionario(nome, cpf, "Admin", senha) {
    // Aqui você pode adicionar lógica específica para Admin se necessário
}

// Destrutor da classe Admin
Admin::~Admin() {
    // Implementação específica para Admin se necessário
}

// Método para acessar o sistema como Admin
void Admin::acessarSistemaAdmin() const{
    cout << "Acesso concedido: Admin\n";
    // Implementação específica para Administrador
}
