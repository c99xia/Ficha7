#pragma once
#include "Coisa.h"
#include <array>
#include <sstream>

class ListaCompra {
public:
    ListaCompra();
    bool adiciona(string nome, int qty); // o retorno é o sucesso da operação
    bool removeQty(string nome, int qty);
    bool elimina(string nome);
    int eliminaTodosMenoresQue(int qty); // o retorno é o número de coisas apagadas
    string obtemDescricao() const;
    Coisa obtemAt(int posicao);
    
private:
    const static int tam = 20;
    
    // std::array cria 20 objetos Coisa imediatamente ao ser declarado.
    // Por isso, Coisa precisa de um construtor sem parâmetros (default).
    // Cada posição fica inicializada com Coisa("", -1) para representar "vazio".
    std::array<Coisa, tam> coisas;
    
    int quantos;  // número de posições realmente ocupadas (0 a tam)
};

