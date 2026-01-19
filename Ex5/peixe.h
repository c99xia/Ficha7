//
// Created by paulo on 04/12/25.
//

#ifndef FICHA7_5_PEIXE_H
#define FICHA7_5_PEIXE_H

#include <string>

class Aquario; //só digo que a classe aquario existe, não sei de mais nada, métodos etc, qual o tamanho do objeto, quantos bytes ocupa na memória só sei que ele existe.

class Peixe {
public:
    Peixe(const std::string& especie,
        const std::string& cor,
        int peso);
    virtual ~Peixe() = default;
    virtual void alimenta(int qt) = 0; //senão tivermos o 0 teriamos que definir a função mas com o corpo vazio != entre =0 e não igual a 0, ou seja virtual puro vs virtual
    std::string obtemDescricao() const;
    int obtemPeso() const { return peso; }
    void alteraAquario(Aquario* a); //sem ser por ponteiro daria erro de compilação, pois ele não sabia o que era o Aquario?
    Peixe(const Peixe& p); //o construtor da cópia com isso impede a cópia do int id.
    //Peixe& operator=(const Peixe& p);
    int obtemID() const { return id; }
    virtual Peixe* clonar() const = 0; //chamar o destrutor da classe derivada carpa e do tubarão, função virtual polimórfica para duplicar peixes
protected:
    void alteraPeso(int peso);
    Aquario* obtemAquario();
private:
    std::string especie;
    std::string cor;
    int peso;
    int id;
    static int nextId;
    Aquario* aquario;
};

std::ostream& operator<<(std::ostream& os, const Peixe& p);

#endif //FICHA7_5_PEIXE_H


/*
 *Polimorfismo (Virtual Peixe* clonar () const = 0;)
 * Tubarao t (....);
 * Peixe *p1 = &t;
 * Peixe *p2 = p1->clonar();
 */

