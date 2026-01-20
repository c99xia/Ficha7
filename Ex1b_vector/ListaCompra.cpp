#include "ListaCompra.h"

bool ListaCompra::adiciona(string nome, int qty) {
    for (int i = 0; i < coisas.size(); i++) {
        if (coisas[i].getNome() == nome) {
            coisas[i].atualizaQty(qty);
            return true;
        }
    }

    coisas[coisas.size()] = Coisa(nome, qty);
    return true;
}

bool ListaCompra::removeQty(string nome, int qty) {
    for (int i = 0; i < coisas.size(); i++) {
        if (coisas[i].getNome() == nome) {
            coisas[i].atualizaQty(-qty);
            if (coisas[i].getQty() == 0) {
                coisas[i] = coisas[coisas.size() - 1];
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
            coisas[i] = coisas[coisas.size() - 1];
            return true;
        }
    }
    return false;
}

int ListaCompra::eliminaTodosMenoresQue(int qty) {
    int contador = 0;
    for (int i = 0; i < coisas.size();) {
        if (coisas[i].getQty() < qty) {
            coisas[i] = coisas[coisas.size() - 1];
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

    }
}
