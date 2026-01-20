#include "ListaCompra.h"

ListaCompra::ListaCompra() : quantos(0) {
}

bool ListaCompra::adiciona(string nome, int qty) {
    for (int i = 0; i < quantos; i++) {
        if (coisas[i].getNome() == nome) {
            coisas[i].atualizaQty(qty);
            return true;
        }
    }

    if (quantos >= tam) {
        return false; // Lista cheia
    }

    coisas[quantos] = Coisa(nome, qty);
    quantos++;
    return true;
}

bool ListaCompra::removeQty(string nome, int qty) {
    for (int i = 0; i < quantos; i++) {
        if (coisas[i].getNome() == nome) {
            coisas[i].atualizaQty(-qty);
            if (coisas[i].getQty() == 0) {
                coisas[i] = coisas[quantos - 1];
                quantos--;
                return true;
            }
            return true;
        }
    }
    return false;
}

bool ListaCompra::elimina(string nome) {
    for (int i = 0; i < quantos; i++) {
        if (coisas[i].getNome() == nome) {
            coisas[i] = coisas[quantos - 1];
            quantos--;
            return true;
        }
    }
    return false;
}

int ListaCompra::eliminaTodosMenoresQue(int qty) {
    int contador = 0;
    for (int i = 0; i < quantos;) {
        if (coisas[i].getQty() < qty) {
            coisas[i] = coisas[quantos - 1];
            quantos--;
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
    for (int i = 0; i < quantos; i++) {
        oss << coisas[i].descricao() << std::endl;
    }
    return oss.str();
}

Coisa ListaCompra::obtemAt(int posicao) {
    if (posicao >= 0 && posicao < quantos) {
        return coisas[posicao];
    }
    return Coisa();  // Posição inválida - retorna Coisa vazia
}
