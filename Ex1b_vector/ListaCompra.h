#pragma once
#include "Coisa.h"
#include <sstream>
#include <vector>

class ListaCompra {
public:
    bool adiciona(string nome, int qty);
    bool removeQty(string nome, int qty);
    bool elimina(string nome);
    int eliminaTodosMenoresQue(int qty);
    string obtemDescricao() const;
    Coisa obtemAt(int posicao);

private:
    // std::vector comeca VAZIO (tamanho 0) - nao cria nenhum objeto Coisa.
    // So cria objetos Coisa quando fazemos push_back(), e nesse momento
    // ja passamos os parametros (nome, qty).
    // Por isso, Coisa NAO precisa de construtor sem parametros (default).
    // 
    // Tambem nao precisamos de "int quantos" porque o vector sabe o seu
    // tamanho atraves de coisas.size().
    std::vector<Coisa> coisas;
};
