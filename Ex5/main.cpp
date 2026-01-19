#include <iostream>

#include "aquario.h"
#include "carpa.h"
#include "peixe.h"
#include "Tubarao.h"

int main() {
    Aquario aquario;
    Carpa c1("azul");
    Carpa c2("vermelho");
    Carpa c3("laranja");
    Tubarao t1("branco");

    aquario.adicionaPeixe(&c1);
    aquario.adicionaPeixe(&c2);
    aquario.adicionaPeixe(&c3);
    aquario.adicionaPeixe(&t1);


    std::cout << aquario << std::endl;

    for (int i = 0; i < 15; i++) {
        aquario.alimentarPeixes(5);
        std::cout << i << ":\n" << aquario << std::endl;
    }

    Aquario aq2 = aquario;
    std::cout << "aquario:\n" << aquario << std::endl;
    std::cout << "copia:\n" << aq2 << std::endl;
    return 0;
}
