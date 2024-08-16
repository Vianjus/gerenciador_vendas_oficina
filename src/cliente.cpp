#include "cliente.h"
#include <iostream>
using namespace std;

// Construtor da classe Cliente, que chama o construtor da classe base Pessoa
Cliente::Cliente(const string& nome, const string& veiculo)
    : Pessoa(nome, ""), veiculo(veiculo) {}

// Destrutor da classe Cliente
Cliente::~Cliente() {
    // Libere a memória alocada para as ordens
    for (Servico* servico : ordens) {
        delete servico;
    }
}

// Implementação de imprimirOrdensPendentes
void Cliente::imprimirOrdensPendentes() const {
    if (ordens.empty()) {
        cout << "Nenhuma ordem encontrada." << endl;
        return;
    }

    cout << "Ordens pendentes:" << endl;
    for (const Servico* servico : ordens) {
        if (servico->isPendente()) {
            servico->imprimir();
        }
    }
}

// Implementação de imprimirOrdensFinalizadas
void Cliente::imprimirOrdensFinalizadas() const {
    if (ordens.empty()) {
        cout << "Nenhuma ordem encontrada." << endl;
        return;
    }

    cout << "Ordens finalizadas:" << endl;
    for (const Servico* servico : ordens) {
        if (servico->isFinalizado()) {
            servico->imprimir();
        }
    }
}

const vector<Servico*>& Cliente::getOrdens() const {
    return ordens;
}