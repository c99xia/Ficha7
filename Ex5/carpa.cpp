//
// Created by Xia on 12/5/2025.
//

#include "carpa.h"

#include "aquario.h"

Carpa::Carpa(const std::string cor) : Peixe("carpa", cor, 5) {
}

void Carpa::alimenta(int qt) {
    int p = obtemPeso();
    p += qt;
    if (p > 50) {
        alteraPeso(20);
        obtemAquario()->adicionaPeixe(this);
    }
    else {
        alteraPeso(p);
    }
}

Peixe* Carpa::clonar() const {
    return new Carpa(*this); //chamar automaticamente o construtor de cópia da classe base Peixe, e gera um id novo.
}

