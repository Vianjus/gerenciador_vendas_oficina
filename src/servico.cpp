#include "servico.h"
using namespace std;

// Construtor da classe Servico
Servico::Servico(string descricao, double preco, int status)
    : Item(descricao, preco) {}

// Destrutor da classe Servico
Servico::~Servico() {}

bool Servico::isValiando() const {
    return status == 0;
}

// Verifica se o serviço está pendente
bool Servico::isPendente() const {
    return status == 1;
}

// Verifica se o serviço está finalizado
bool Servico::isFinalizado() const {
    return status == 2;
}

// Imprime informações do serviço
void Servico::imprimir() const {
    string estado = (status == 1) ? "Pendente" : "Finalizada";
    cout << "Descricao: " << descricao << "\n"
              << "Preco: $" << preco << "\n"
              << "Status: " <<  estado
              << endl;

}

void Servico::marcarComoPendente() {
    if (status == 0) { // Se está pendente
        status = 1; // Marque como finalizado
    }
}

void Servico::marcarComoFinalizado() {
    if (status == 1) { // Se está pendente
        status = 2; // Marque como finalizado
    }
}