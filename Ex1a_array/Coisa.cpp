#include "Coisa.h"

// Construtor normal: garante que qty nunca é negativa
Coisa::Coisa(string n, int q) : nome(n), qty(q > 0 ? q : 0) {}

// Construtor default: cria item "vazio" com qty = -1 para distinguir de itens reais
// Necessário porque std::array<Coisa, N> cria N objetos automaticamente
Coisa::Coisa() : nome(""), qty(-1) {}

string Coisa::getNome() const { return nome; }
int Coisa::getQty() const { return qty; }

// Atualiza quantidade, garantindo que nunca fica negativa
void Coisa::atualizaQty(int dif) {
    qty += dif;
    if (qty < 0)
        qty = 0;
}

string Coisa::descricao() const {
    return nome + " " + std::to_string(qty);
}