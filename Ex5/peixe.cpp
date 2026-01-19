//
// Created by Xia on 12/5/2025.
//

#include "peixe.h"

#include <iostream>
#include <sstream>

int Peixe::nextId = 1000;

Peixe::Peixe(const std::string& especie, const std::string& cor, int peso) : especie(especie), cor(cor), peso(peso),
id(nextId++), aquario(nullptr) {
}

Peixe::Peixe(const Peixe& p) {
    //construtor por cópia
    especie = p.especie;
    cor = p.cor;
    peso = p.peso;
    aquario = nullptr;
    //um aquario e um peixe, o aquario tem uma coleção de peixes e tem uma lista de peixes, o peixe está dentro dessa coleção, ao duplicar o peixe ele não está no aquário.
    //no memento de copiar ele não fica no aquário o peixe
    id = nextId++; //muito importante
}

void Peixe::alteraPeso(int peso) {
    if (peso < 0) {
        return;
    }
    this->peso = peso;
}

Aquario* Peixe::obtemAquario() {
    return aquario;
}

std::string Peixe::obtemDescricao() const {
    std::ostringstream o;
    o << id << ":" << especie << " " << cor << " " << peso << std::endl;
    return o.str();
}

std::ostream& operator <<(std::ostream& os, const Peixe& p) { //global
    os << p.obtemDescricao();
    return os;
}

void Peixe::alteraAquario(Aquario* a) {
    aquario = a;
}

