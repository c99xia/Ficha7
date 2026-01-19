//
// Created by paulo on 04/12/25.
//

#ifndef FICHA7_5_AQUARIO_H
#define FICHA7_5_AQUARIO_H

class Peixe;
#include <string>
#include <vector>

class Aquario {
public:
    Aquario();

    ~Aquario();

    void adicionaPeixe(Peixe* p);

    bool eliminaPeixe(int id);

    int obtemOutroPeixe(int id) const;

    const Peixe* obtemPeixe(int id) const;

    void alimentarPeixes(int qt);

    std::string obtemDescricao() const;

    Aquario(const Aquario& a);

    Aquario& operator=(const Aquario& a);

private:
    std::vector<Peixe*> peixes;

    bool em_alimentacao;
    std::vector<int> para_eliminar;
    std::vector<Peixe*> para_adicionar;
};

std::ostream& operator<<(std::ostream& os, const Aquario& a);

#endif //FICHA7_5_AQUARIO_H
