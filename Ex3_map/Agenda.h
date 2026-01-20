#pragma once
#include "Contacto.h"
#include <map>

class Agenda {
public:
    bool insere(string nome, string morada, int tel);
    bool elimina(string nome);
    int obtemTelefone(string nome) const;
    string obtemMorada(string nome) const;
    bool atualizaTelefone(string nome, int tel);
    bool atualizaMorada(string nome, string morada);
    bool atualizaNome(string nomeAntigo, string nomeNovo);
    string obtemLista() const;
private:
    std::map <string, Contacto> contactos;
};

