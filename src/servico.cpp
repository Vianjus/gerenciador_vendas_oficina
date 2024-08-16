#include "servico.h"

// Construtor da classe Servico
Servico::Servico(string descricao, double preco, int tipoServico)
    : Item(descricao, preco), valor(tipoServico == 1 ? 100 : 1000), status(1), tipoServico(tipoServico) {}

// Destrutor da classe Servico
Servico::~Servico() {}

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
    std::cout << "Descricao: " << descricao << "\n"
              << "Preco: $" << preco << "\n"
              << "Valor: $" << valor << "\n"
              << "Status: " << (status == 1 ? "Pendente" : "Finalizado") << "\n"
              << "Tipo de Servico: " << (tipoServico == 1 ? "Revisao" : "Manutencao") << "\n";
}

void Servico::marcarComoFinalizado() {
    if (status == 1) { // Se está pendente
        status = 2; // Marque como finalizado
    }
}