#include "ListaCompra.h"

// =============================================================================
// DIFERENÇAS ENTRE ARRAY E VECTOR:
// 
// ARRAY (Ex1a):
//   - Tamanho FIXO definido na declaração (ex: 20)
//   - Precisa de "int quantos" para saber quantos estão ocupados
//   - Adicionar: coisas[quantos] = Coisa(...); quantos++;
//   - Remover: coisas[i] = coisas[quantos-1]; quantos--;
//   - Precisa de construtor Coisa() default
//
// VECTOR (Ex1b):
//   - Tamanho VARIÁVEL, cresce e diminui automaticamente
//   - Usa coisas.size() para saber o tamanho
//   - Adicionar: coisas.push_back(Coisa(...));
//   - Remover: coisas[i] = coisas.back(); coisas.pop_back();
//   - NAO precisa de construtor default
// =============================================================================

bool ListaCompra::adiciona(string nome, int qty) {
    for (int i = 0; i < coisas.size(); i++) {
        if (coisas[i].getNome() == nome) {
            coisas[i].atualizaQty(qty);
            return true;
        }
    }

    coisas.push_back(Coisa(nome, qty)); // VECTOR: push_back adiciona ao fim
    return true;
}

bool ListaCompra::removeQty(string nome, int qty) {
    for (int i = 0; i < coisas.size(); i++) {
        if (coisas[i].getNome() == nome) {
            coisas[i].atualizaQty(-qty);
            if (coisas[i].getQty() == 0) {
                coisas[i] = coisas.back();   // Copia o último para esta posição
                coisas.pop_back();            // VECTOR: pop_back remove o último
                return true;
            }
            return true;
        }
    }
    return false;
}

bool ListaCompra::elimina(string nome) {
    for (int i = 0; i < coisas.size(); i++) {
        if (coisas[i].getNome() == nome) {
            coisas[i] = coisas.back();   // Copia o último para esta posição
            coisas.pop_back();            // VECTOR: pop_back remove o último
            return true;
        }
    }
    return false;
}

int ListaCompra::eliminaTodosMenoresQue(int qty) {
    int contador = 0;
    for (int i = 0; i < coisas.size();) {
        if (coisas[i].getQty() < qty) {
            coisas[i] = coisas.back();   // Copia o último para esta posição
            coisas.pop_back();            // VECTOR: pop_back remove o último
            contador++;
        }
        else {
            i++; // só avança depois de verificar o elemento
        }
    }
    return contador;
}

string ListaCompra::obtemDescricao() const {
    std::ostringstream oss;
    for (int i = 0; i < coisas.size(); i++) {
        oss << coisas[i].descricao() << std::endl;
    }
    return oss.str();
}

Coisa ListaCompra::obtemAt(int posicao) {
    if (posicao >= 0 && posicao < coisas.size()) {
        return coisas[posicao];
    }
    else {
        throw std::invalid_argument("Posicao invalida");
    }
}
