#ifndef VEICULO_H
#define VEICULO_H

#include <string>
using namespace std;

class Veiculo {
private:
    string modelo;
    string placa;
    double km;

public: 
    Veiculo(string modelo, string placa, double km);
    virtual ~Veiculo();

    void setModelo(string modelo);
    string getModelo(); 

    void setPlaca(string placa);
    string getPlaca();

    void setKm(double km);
    double getKm();
};

#endif // VEICULO_H