#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pessoa {
protected: 
    string nome;
    string cpf;

public: 
    Pessoa(string nome, string cpf) : nome(nome), cpf(cpf) {}
    virtual ~Pessoa() {}

    void setNome(string nome) { this->nome = nome; }
    string getNome() { return nome; }

    void setCpf(string cpf) { this->cpf = cpf; }
    string getCpf() { return cpf; }   
};

class Funcionario : public Pessoa {
protected: 
    string cargo;

public:
    Funcionario(string nome, string cpf, string cargo) : Pessoa(nome, cpf), cargo(cargo) {}
    virtual ~Funcionario() {}

    void setCargo(string cargo) { this->cargo = cargo; }
    string getCargo() { return cargo; }    
};

class Vendedor: public Funcionario {
public:
    Vendedor(string nome, string cpf) : Funcionario(nome, cpf, "Vendedor") {}
};

class Mecanico: public Funcionario {
public:
    Mecanico(string nome, string cpf) : Funcionario(nome, cpf, "Mecanico") {}
};

class Veiculo {
private:
    string modelo;
    string placa;
    double km;

public: 
    Veiculo(string modelo, string placa, double km) : modelo(modelo), placa(placa), km(km) {}
    virtual ~Veiculo() {}

    void setModelo(string modelo) { this->modelo = modelo; }
    string getModelo() { return modelo; } 

    void setPlaca(string placa) { this->placa = placa; }
    string getPlaca() { return placa; }

    void setKm(double km) { this->km = km; }
    double getKm() { return km; }
};

class Cliente : public Pessoa {
private:
    vector<Veiculo> veiculos;

public: 
    Cliente(string nome, string cpf) : Pessoa(nome, cpf) {}
    virtual ~Cliente() {}

};

class Item {
protected:
    string descricao;
    double preco;

public:
    Item(string descricao, double preco) : descricao(descricao), preco(preco) {}
    virtual ~Item() {}

    void setDescricao(string descricao) { this->descricao = descricao; }
    string getDescricao(){ return descricao; }

    void setPreco(double preco) { this->preco = preco; }
    double getPreco() { return preco; }
};

class Servico : public Item {
public:
    Servico(string descricao, double preco) : Item(descricao, preco) {}
    virtual ~Servico() {}
};

class Produto : public Item {
public:
    Produto(string descricao, double preco) : Item(descricao, preco) {}
    virtual ~Produto() {}
};

int main(){
  cout << "Hello World!";
  return 0;
}


