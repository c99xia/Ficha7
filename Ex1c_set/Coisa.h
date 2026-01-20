#pragma once
#include <string>
using std::string;
#include <stdexcept>

// Representa um item a comprar (nome + quantidade)
class Coisa {
public:
    //Coisa();                  Vector não precisa de construtor default
    Coisa(string n, int q);     // Construtor normal - cria item com nome e quantidade
    string getNome() const;
    int getQty() const;
    void atualizaQty(int dif);
    string descricao() const;

    //Operador
    bool operator<(const Coisa& outro) const;

private:
    string nome;
    int qty;
};

