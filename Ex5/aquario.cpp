//
// Created by Xia on 12/5/2025.
//

#include "aquario.h"
#include <sstream>
#include "peixe.h"


Aquario::Aquario() : em_alimentacao(false) {
}

void Aquario::alimentarPeixes(int qt) {
    em_alimentacao = true;
    for (auto it = peixes.begin(); it != peixes.end(); it++) {
        (*it)->alimenta(qt);
    }
    em_alimentacao = false;
    if (!para_adicionar.empty()) {
        for (Peixe* p : para_adicionar) {
            peixes.push_back(p);
        }
    }
    para_adicionar.clear();

    if (!para_eliminar.empty()) {
        for (auto it = para_eliminar.begin(); it != para_eliminar.end(); ++it) {
            eliminaPeixe(*it);
        }
    }
    para_eliminar.clear();
}

void Aquario::adicionaPeixe(Peixe* p) {
    Peixe* clone = p->clonar();
    clone->alteraAquario(this);
    if (em_alimentacao) {
        para_adicionar.push_back(clone);
    }
    else {
        peixes.push_back(clone);
    }
}

Aquario::Aquario(const Aquario& a) {
    //em_alimentacao=a.em_alimentacao;
    for (const Peixe* p : a.peixes) {
        Peixe* clone = p->clonar();
        clone->alteraAquario(this);
        peixes.push_back(clone);
    }
}

bool Aquario::eliminaPeixe(int id) {
    for (auto it = peixes.begin(); it != peixes.end(); it++) {
        if ((*it)->obtemID() == id) {
            if (em_alimentacao) {
                para_eliminar.push_back(id);
            }
            else {
                delete (*it);
                peixes.erase(it);
                peixes.shrink_to_fit();
            }
            return true;
        }
    }
    return false;
}

std::string Aquario::obtemDescricao() const {
    std::ostringstream os;
    for (const Peixe* p : peixes) {
        os << *p << "\n";
    }
    return os.str();
}

int Aquario::obtemOutroPeixe(int id) const {
    for (const Peixe* p : peixes) {
        if (p->obtemID() != id) {
            return p->obtemID();
        }
    }
    return -1;
}

const Peixe* Aquario::obtemPeixe(int id) const {
    //o ponteiro que é devolvido não é permitido alterar o peixe
    for (const Peixe* p : peixes) {
        if (p->obtemID() == id) {
            return p;
        }
    }
    return nullptr;
}

Aquario& Aquario::operator=(const Aquario& a) {
    //temos aqui três aquários aqui envolvidos
    Aquario temp(a); //este temp é a cópia da cópia do aquario, o temp contém o clone da cópia do aquário
    using std::swap;
    swap(temp.peixes, peixes);
    return *this;
} //no final o aquário deixa de existir?

Aquario::~Aquario() {
    for (const Peixe* p : peixes) {
        delete p;
    }
}

std::ostream& operator <<(std::ostream& os, const Aquario& a) {
    //global
    os << a.obtemDescricao();
    return os;
}
