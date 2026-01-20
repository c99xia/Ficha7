#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
using std::string;

class Contacto {
public:
    Contacto(string n, string m, int tel);
    string getNome() const;
    string getMorada() const;
    int getTelef() const;
    void mudaMorada(string m);
    void mudaTelef(int tel);
    string descricao() const;
private:
    string nome;
    string morada;
    int telef;
};

