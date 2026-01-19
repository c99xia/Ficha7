//
// Created by Xia on 12/12/2025.
//

#ifndef EX5_TUBARAO_H
#define EX5_TUBARAO_H
#include "peixe.h"


class Tubarao : public Peixe {
public:
    Tubarao(const std::string cor);

    void alimenta(int qt) override;

    Peixe* clonar() const override;
};


#endif //EX5_TUBARAO_H
