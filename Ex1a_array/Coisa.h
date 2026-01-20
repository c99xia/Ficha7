#pragma once
#include <string>
using std::string;

// Representa um item a comprar (nome + quantidade)
class Coisa {
public:
    Coisa();                    // Construtor default - cria item "vazio" (qty = -1)
    Coisa(string n, int q);     // Construtor normal - cria item com nome e quantidade
    string getNome() const;
    int getQty() const;
    void atualizaQty(int dif);
    string descricao() const;
    
private:
    string nome;
    int qty;
};

