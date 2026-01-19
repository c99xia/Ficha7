//
// Created by Xia on 12/12/2025.
//

#include "Tubarao.h"
#include "aquario.h"


Tubarao::Tubarao(const std::string cor) : Peixe("Tubarao", cor, 15) {
}

void Tubarao::alimenta(int qt) {
    int p = obtemPeso();
    if (p < 5) {
        //se o tubarao está com fome
        obtemAquario()->eliminaPeixe(obtemID());
    }
    else if (p > 20) {
        alteraPeso(p - 1);
    }
    else {
        Aquario* aq = obtemAquario();
        int idOutro = aq->obtemOutroPeixe(obtemID());
        if (idOutro >= 0) {
            const Peixe* peixe = aq->obtemPeixe(idOutro);
            alteraPeso(p + peixe->obtemPeso());
            aq->eliminaPeixe(idOutro);
        }
        else if (p < 20) {
            alteraPeso(p - 2);
        }
    }
}

Peixe* Tubarao::clonar() const {
    return new Tubarao(*this);
}
