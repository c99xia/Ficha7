#include "Coisa.h"

// Construtor normal: garante que qty nunca é negativa
Coisa::Coisa(string n, int q) : nome(n), qty(q > 0 ? q : 0) {}

//Vector não é necessário construtor default
//Coisa::Coisa() : nome(""), qty(-1) {} 


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

// OPERADOR NECESSÁRIO PARA std::set
// ===================================
// O std::set é uma coleção ORDENADA que mantém os elementos automaticamente
// organizados segundo um critério de comparação.
// 
// Para funcionar, o set EXIGE que os elementos implementem o operator< ou
// forneçam um comparador customizado.
//
// COMO FUNCIONA:
// - Quando inserimos um elemento, o set usa operator< para encontrar a posição correta
// - O set NÃO permite elementos duplicados (se a < b for falso E b < a for falso,
//   então a e b são considerados "equivalentes" e apenas um ficará no set)
// - A busca, inserção e remoção são muito eficientes: O(log n)
//
// NESTE CASO:
// - this = objeto da ESQUERDA na comparação (a < b, "a" é o this)
// - outro = objeto da DIREITA na comparação (a < b, "b" é o outro)
// - Ordenamos alfabeticamente pelo NOME (exercício 1c exige ordenação)
//
// DIFERENÇA PARA vector:
// - vector: ordem de inserção, permite duplicados, operator< não obrigatório
// - set: ordem automática (alfabética aqui), não permite duplicados, operator< obrigatório
bool Coisa::operator<(const Coisa& outro) const {
    return nome < outro.nome; // Comparação alfabética: this->nome < outro.nome
}