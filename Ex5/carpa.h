//
// Created by Xia on 12/5/2025.
//

#ifndef EX5_CARPA_H
#define EX5_CARPA_H
#include "peixe.h"


class Carpa : public Peixe {
public:
    Carpa(const std::string cor); //porque só tem esse atributo variável, a especíe é fixa, tem o peso fixo, e só a cor variável
    void alimenta(int qt) override;

protected:  //pode ser public
    Peixe* clonar() const override;
};


#endif //EX5_CARPA_H