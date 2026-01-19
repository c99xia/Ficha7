## Page 1

&lt;img&gt;ISEC Engenharia logo&lt;/img&gt;

Instituto Superior de Engenharia de Coimbra
Departamento de Engenharia Informática e de Sistemas
Engenharia Informática

---

# Programação Orientada a Objetos 2025/2026

## Exercícios

**Ficha Nº 7**
Coleções: array, vector, set, map (opcional: Algoritmos)

1. Listas de coisas a comprar – Várias versões

Este exercício compreende várias versões da mesma funcionalidade. **Não pode usar arrays clássicos** de C/C++ nem memória dinâmica. Existe uma classe dada como ponto de partida, que pode modificar à medida que vai fazendo as alíneas, mas apenas se fizer sentido e tem de justificar a alteração feita.
Ponto de partida: considere a classe **Coisa** apresentada abaixo. Representa coisas a comprar.

Coisa.h
```c++
// includes e outras declarações omitidos

class Coisa {
public:
    Coisa(string n, int q);
    string getNome() const;
    int getQty () const;
    void atualizaQty(int dif);
    string descricao() const
private:
    string nome;
    int qty
};
```

Coisa.cpp
```c++
// includes e outras declarações omitidos
#include "Coisa.h"

Coisa::Coisa(string n, int q) : nome(n), qty(q > 0? q : 0) {}

string Coisa::getNome() const { return nome; }
int Coisa::getQty () const { return qty; }
void Coisa::atualizaQty (int dif) {
    qty += dif;
    if (dif < 0)
        dif = 0;
}
string Coisa::descricao() const {
    return nome: + " " + to_string(qty);
}
```

ISEC/DEIS – Engenharia Informática
Programação Orientada a Objetos - 25/26
&lt;page_number&gt;1 / 10&lt;/page_number&gt;

---


## Page 2

# Lista de compras

Pretende-se que, ao longo das alíneas seguintes, construa uma classe que representa uma lista de compras de tamanho fixo com a seguinte funcionalidade:

*   Inserir uma nova coisa a comprar dado o nome da coisa e a quantidade. Se a coisa já estiver na lista, deve acrescentar a quantidade ao que já lá estiver. Função **adiciona(nome da coisa, quantidade)**.
*   Remover uma quantidade a comprar de uma determinada coisa. Se chegar a quantidade chegar a zero, remova-a.. Função **removeQty(nome da coisa, quantidade)**.
*   Eliminar uma coisa a comprar dada o seu nome. Função **remove(nome da coisa)**.
*   Eliminar todas as coisas que tenham uma quantidade menor que o indicado. Função **remove(quantidade)**.
*   Obter uma cópia da coisa registada numa detemiada posição. Esta funcionalidade poderá não ser feita em algumas das versões da ListaDeCompras, ou, se for, será uma implementação fraca e lenta. Função **obtemAt(posição)**.
*   Obter a lista de coisas a a comprar, uma coisa (e quantidade) por linha. Obviamente, a classe não imprime nada para o ecrã. Função **obtemDescricao()**.
*   Inicialmente o conjunto de coisas a comprar está vazio.

Pode usar como base de trabalho a classe **ListaDeCompras** cujo .h incompleto se apresenta a seguir Cada alínea introduz uma pequena variação, pelo que deve fazer várias classes para a lista de compras (sugestão: mude o nome da classe ListaDeCompras acrescento-lhe o nome da coleção que vai usar).

## ListaCompras.h

```c++
// includes e outras declarações omitidos

class ListaCompras {
public:
    bool adiciona(string nome, int qty); // o retorno é o sucesso da operação
    bool removeQty(string nome, int qty);
    bool elimina(string nome);
    int eliminaTodosMenoresQue(int qty); // o retorno é o número de coisas apagadas
    string obtemDescricao() const;
    Coisa obtemAt(int posição); // poderá não ser possível fazer esta
private:
    // Uma coleção do tipo apropriado à alínea que está a fazer
    // talvez não precise disto - pense bem primeiro: int quantos;
};
```

a) Implemente uma lista de compras **de tamanho fixo**. O tamanho é 20. Antes de começar a escrever código, responda às seguintes questões:

i) Qual a coleção mais adequada (a que responde aos requisitos sem introduzir *overheads desnecessários*)? Sugestão: não se pretende usar uma colação vector nesta alínea.

ii) Estará a coleção que usou alguma vez efetivamente vazia? Ou será que existe a necessidade de representar um item Compra “vazio”? Se sim, como vai representar esse caso?

ISEC/DEIS – Engenharia Informática Programação Orientada a Objetos - 25/26 &lt;page_number&gt;2 / 10&lt;/page_number&gt;

---


## Page 3

b) Implemente uma lista de compras que **não tem tamanho fixo**, podendo estar realmente vazia (sem item nenhum), e cujo tamanho máximo depende apenas da memória disponível. Antes de começar a escrever código, responda às seguintes questões:

i) Qual a coleção mais adequada (a que responde aos requisitos sem introduzir *overheads desnecessários*)?

ii) Não é suposto ser necessário representar um item ListaCompras “vazio”. Verifique que não tem coisas desnecessárias na classe ListaCompras e na classe Coisa.

c) Implemente uma lista de compras semelhante à que fez na alínea b, mas com a seguinte particularidade: os itens a comprar estão sempre **ordenados por nome** (ordem alfabética), mesmo que os insira por outra ordem. Antes de começar a escrever código, reflita no seguinte:

i) Qual a coleção mais adequada (a que responde aos requisitos sem introduzir *overheads desnecessários* e lhe poupa trabalho)?

No final do exercício deverá ter

* Usado coleções para armazenar objetos – array, vector, set
* Experimentado as operações básicas em coleções: inserir, procurar, eliminar, iterar
* Ter usado iteradores

2. Opcional (TPC / Desafio) – Algoritmos

Escreva uma nova versão do exercício 1 usando o mais que puder os algoritmos da biblioteca standard e expressões lambda. Este exercício visa promover a iniciativa e o interesse, sendo acompanhado apenas por solicitação daqueles que estiverem interessados em o realizar.

* Aceda à lista de algoritmos standard e identifique os algoritmos que podem ser úteis (por exemplo: procurar, contar, eliminar);
* Veja os requisitos desses algoritmos e a descrição exata daquilo que realmente fazem;
* Aplique-os, usando expr3ssões lambda onde necessário.

No final do exercício deverá ter

* Usado algoritmos standard e expressões lambda no contexto de coleções

3. Agenda de contactos – sem arrays nem memória dinâmica

Pretende-se implementar uma classe Agenda que representa uma vulgar agenda de contactos (funcionalidade exata descrita mais abaixo). O contacto é representado pela classe já fornecida, cujo código se encontra abaixo.

ISEC/DEIS – Engenharia Informática
Programação Orientada a Objetos - 25/26
&lt;page_number&gt;3 / 10&lt;/page_number&gt;

---


## Page 4

Contacto.h

```c++
// includes e outras declarações omitidos

class Contacto {
public:
    Contacto(string n, string m, int tel);
    string getNome() const;
    int getMorada() const;
    int getTelef() const;
    void mudaMorada(string m);
    void mudaTelef(int tel);
    string descricao() const;
private:
    string nome;
    string morada;
    int telef;
};
```

Contacto.cpp

```c++
// includes e outras declarações omitidos

Contacto::Contacto(string n, string m, int tel) : nome (n), morada(m), telef(tel) {}
string Contacto::getNome() const { return nome; }
int Contacto::getMorada() const { return morada; }
int Contacto::getTelef() const { return telef; }
void Contacto::mudaMorada(string m) { morada = m; }
void Contacto::mudaTelef(int tel) { telef = tel; }
string Contacto::descricao() const {
    return nome + " " + morada + " " + to_string(telef);
}
```

A agenda a implementar deve associar nomes aos respetivos contactos da forma mais direta possível.
Deve ter a seguinte funcionalidade (use o código fornecido mais abaixo como ponto de partida):

*   Permite inserir um novo contacto, ficando associado a esse nome
*   Permite eliminar um contacto dado o seu nome
*   Permite obter o telefone associado a um determinado nome
*   Permite obter a morada associada a um determinado nome
*   Permite atualizar o telefone associado a um determinado nome
*   Permite atualizar a morada associado a um determinado nome
*   Permite mudar o nome, mantendo os restantes dados, dado o nome antigo e o novo nome.
*   Permite obter a lista completa dos contactos, um contacto por linha, e não se trata de imprimir coisas no ecrã

Já existe um .h da classe Agenda, que deve utilizar para poupar tempo e para ter uma ideia mais concreta daquilo que é a funcionalidade esperada desta classe. O exercício corresponde em implementar o .cpp correspondente e a experimentar a funcionalidade numa função main sintética e simples.

ISEC/DEIS – Engenharia Informática Programação Orientada a Objetos - 25/26 &lt;page_number&gt;4 / 10&lt;/page_number&gt;

---


## Page 5

Agenda.h

```c++
// includes e outras declarações omitidos

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
    // Uma coleção do tipo apropriado à alínea que está a fazer
    // em princípio, não precisa disto: int quantos
};
```

No final do exercício deverá ter
* Usado a coleção map
* Experimentado as operações básicas em maps: inserir, procurar, eliminar, iterar
* Ter usado iteradores em maps

4. **País / Clube / Pessoas** – Composição e agregação com coleções

Pretende-se representar pessoas que pertencem a um país e participam em clubes.
* Um clube é constituído por um conjunto de pessoas que partilham o interesse por uma determinada atividade.
* As pessoas são descritas pela sua própria classe. Deve usar a classe dada mais abaixo.
* As pessoas não existem dentro do clube: têm vida e existência própria para além do clube e alojadas em qualquer outra parte do programa. Mais especificamente, as pessoas pertencem a um país, que é representado pela sua própria classe. Não deverá ter objetos de Pessoa espalhados pela função main: deve ter um objeto País, o qual tem e controla os objetos de Pessoa.

Pessoa.h

```c++
// includes e outras declarações omitidos

class Pessoa {
public:
    Pessoa(string nome, int bi, int nif);
    string getNome() const;
    int getBI() const; // Critério de igualdade é o BI ("cartão de cidadão")
    int getNIF() const;
    void setNome(string nome);
    string descricao() const;
private:
    string nome;
    int bi, nif;
};
```

ISEC/DEIS – Engenharia Informática Programação Orientada a Objetos - 25/26 &lt;page_number&gt;5 / 10&lt;/page_number&gt;

---


## Page 6

Pessoa.cpp

```cpp
// includes e outras declarações omitidos

Pessoa::Pessoa(string _nome, int _bi, int _nif) : nome(_nome), bi(_bi), nif(_nif) { }
string Pessoa::getNome() const { return nome; }
int Pessoa::getBI() const { return bi; }
int Pessoa::getNIF() const { return nif; }
void Pessoa::setNome(string _nome) { nome = _nome; }
string Pessoa::descricao() const {
    ostringstream oss;
    oss << nome << " / " << bi << " / " << nif;
    return oss.str();
}
```

a) **País** – Composição de recursos dinâmicos com coleções

Escreva a classe **País**. Um país tem um nome e um conjunto de pessoas. E ainda:

*   Na sua inicialização exige o nome do país. Não existe um número máximo de pessoas. Inicialmente não tem pessoa nenhuma.
*   É possível obter, mas não mudar o nome do país.
*   Permite adicionar uma nova pessoa, a qual é construída no contexto da classe e não fora dela. Para esta operação são indicados os dados da nova pessoa. A operação falha se já existir nesse país uma pessoa com o BI indicado.
*   Permite obter o nome de uma pessoa dado o seu BI.
*   Permite obter a listagem de todas as pessoas numa *string*, uma pessoa por linha.
*   Permite atualizar o nome de uma pessoa dado o seu BI e o novo nome.
*   Permite obter o número de pessoas atualmente existentes no país.
*   Permite obter o ponteiro para uma pessoa dado o BI. Esta funcionalidade é discutível (e é importante que perceba porquê), mas é necessária ao clube. O ponteiro devolvido não deve permitir a alteração do objeto apontado.
*   Apagar uma pessoa dado o BI. Se o resto do programa estiver na posse de umponteiro, poderá haver problemas e essa é mais uma razão (mas não a única) pela qual a obtenção de um ponteiro é problemática e discutível.
*   Transferir uma pessoa para outro País dados o BI da pessoa e o País destino. A operação falha se no registo civil destino já existir esse BI.

Nada é dito acerca da forma como os objetos de País vão ser usados, por isso deve assumir que poderá acontecer atribuir e passar por cópia objetos desta classe. Pense nisso e veja se precisa de fazer alguma coisa que não tenha sido pedida explicitamente (porque não precisa sequer de ser pedida).

ISEC/DEIS – Engenharia Informática Programação Orientada a Objetos - 25/26 &lt;page_number&gt;6 / 10&lt;/page_number&gt;

---


## Page 7

b) + c) Clube – Agregação com coleções

Escreva a classe **Clube**. Um clube tem um nome e conhece um conjunto de pessoas. E ainda:

*   Tem um nome e conhece um conjunto de pessoas, sem limite predefinido. Conhece também o país a que as pessoas pertencem. Mais adiante será dito algo mais acerca da forma como conhece o Pais e as pessoas.
*   Um objeto de Clube só pode ser criado mediante a indicação do seu nome e do conhecimento do país. Inicialmente não existem pessoas nesse clube.
*   Deve ser possível acrescentar uma pessoa a um clube. Acrescentar uma pessoa significa fazer essa pessoa (que já existe) sócia do clube. A pessoa não passa a “viver” na sede do clube - simplesmente o clube passa a saber que a pessoa existe e deixa-a entrar nas instalações. Esta descrição é importante para que possa determinar exatamente qual é a forma como os objetos de Clube vão ver os objetos de Pessoa.
    *   **Nota:** muito cuidado na forma como passa a pessoa a adicionar por parâmetro à função que trata desta questão. Das três formas que conhece de passar parâmetros em funções, uma não é compatível com este exercício. Uma escolha errada pode levar ao crash do programa mais tarde. Confirme com o professor que fez uma escolha adequada.
*   Deve ser possível saber se uma pessoa é sócia do clube dado o seu número de BI.
*   Deve ser possível remover um sócio do clube dado o número de BI.
*   Deve ser possível listar os dados de todos os sócios de um clube.

Implementação: as pessoas a usar no Clube são geridas pelo **Pais** da alínea anterior. Tem duas alternativas:

A. O clube sabe que o Pais existe e dirige-se a este para obter dados sobre os sócios. Precisa apenas de armazenar o número de BI dos sócios e o conhecimento que o País existe. É muito fácil saber se um BI deixou de ser válido (a pessoa em questão emigrou) porque o RegistoCivil intermedia todos os acessos aos dados da Pessoa por parte do Clube, bastando analisar algum código de erro que o Pais retorna quando se procura uma pessoa dado o BI.

B. O clube armazena “referências” (referencias/ponteiros) para as pessoas. Essas referências foram passadas ao clube quando se acrescentou o sócio. Não precisa de saber que o Pais existe. O Clube fica fragilizado na medida em que a pessoa pode deixar de existir sem que o clube se aperceba e as referências /ponteiros para as pessoas (sócios) podem estar já inválidas sem que o Clube o saiba.

b) Escreva a classe **Clube** através da estratégia **A**. Identifique o tipo de associação existente entre a classe **Clube** e a classe **Pais**, e a forma de implementação adequada face ao necessário e à matéria já dada.

c) Escreva a classe **Clube** através da estratégia **B**. Identifique o tipo de associação existente entre a classe **Clube** e a classe **Pessoa**, e a forma de implementação adequada face ao necessário e à matéria já dada.

ISEC/DEIS – Engenharia Informática
Programação Orientada a Objetos - 25/26
&lt;page_number&gt;7 / 10&lt;/page_number&gt;

---


## Page 8

No final deste exercício é suposto

*   Ter revisto os conceitos de composição e agregação de objetos, incluindo as diferenças entre os dois conceitos e os cenários em que se deve aplicar um ou o outro.
*   Ter revisto a gestão de recursos dinâmicos.
*   Ter usado coleções de ponteiros como mecanismo auxiliar na gestão de recursos dinâmicos
*   Ter percebido qual o papel de coleções num cenário de gestão e recursos dinâmicos e a forma como poupa algum trabalho, mas não todo.
*   Ter revisto a forma de escolher referências vs. Ponteiros como mecanismo de agregação

5. **Aquário com peixes diversos**

Pretende-se um programa que simule a existência de **peixes** de diversas espécies num **aquário**.

**Acerca dos peixes:** Há muitas espécies. Todas elas exibem as seguintes características comuns:

*   Aparentam ter um nome da espécie (texto), uma cor (texto), um peso (gramas), ID (número de série que é um valor automaticamente atribuído e sempre crescente começando em 1000).

Permitem:

*   (TPC) Apresentar os seus dados com operações cout << peixe1 << peixe2 << etc.;
*   Os peixes têm a possibilidade de serem alimentados com uma certa quantidade em gramas de comida. Existem diversas espécies de peixes e cada espécie exibe um comportamento diferente quando é alimentado.

Há muitas espécies de peixes. O enunciado aborda apenas duas, sem que isso constitua uma autorização para simplificações indevidas:

*   **Carpa**: acrescente ao seu peso os gramas de comida que lhe é dada. Se o seu peso exceder 50, divide-se em dois, ficando o original com 20 gramas, e passando a existir no aquário um novo peixinho com as mesmas características (mesma cor etc. mas com um número de série diferente). As carpas têm sempre o nome de espécie “carpa” e têm inicialmente o peso 5.
*   **Tubarão**: ignora a comida que lhe é dada. Se tiver mais do que 20 gramas, diminui um grama de peso. Se tiver menos de 20 gramas procura um outro peixe qualquer e come-o, acrescentando ao seu peso o peso do peixe ingerido. Se não houver nenhum peixe para comer e já tiver menos de 20 gramas, diminui o seu peso em 2 gramas. Se tiver menos de 5 gramas morre. Tem sempre o nome de espécie “Tubarão” e o peso inicial de 15.

**Acerca do aquário:** tem uma quantidade indeterminada de peixes. Possui mecanismos para:

*   Acrescentar um novo peixe. O peixe é “apresentado” ao aquário, o qual faz duplicado dele, guardando-o e controlando-o em exclusivo.

**Importante:** Este comportamento (guardar uma cópia) não é coerente com o que se passa na vida real, mas é coerente com o que tem que acontecer face ao que já foi discutido quanto às classes que assumem a posse dos seus objetos dinâmicos. Este assunto é importante e, em caso de dúvida, pergunte ao professor as razões e quais as alternativas.

ISEC/DEIS – Engenharia Informática
Programação Orientada a Objetos - 25/26
&lt;page_number&gt;8 / 10&lt;/page_number&gt;

---


## Page 9

*   Eliminar um peixe dado o seu ID.
*   Dado o ID de um peixe, obter o ID de um outro peixe qualquer (um qualquer menos esse) (-1 se não houver).
*   Obter o ponteiro para um peixe dado o seu ID. Deve proteger esse peixe contra modificações.
*   Alimentar os peixes com uma dada quantidade de comida.
*   Produzir uma cadeia de caracteres com a descrição de todos os peixes.

O aquário pode ser copiado. Os dois aquários ficam com conteúdo **equivalente** (apenas os números de série dos peixes serão diferentes) mas totalmente independentes um do outro.

**Ajuda1:** O processo de alimentação de um peixe pode modificar a estrutura de peixes no aquário: pode haver peixes a morrer ou peixes novos acrescentados. O ciclo que percorre essa estrutura, alimentando um peixe de cada vez, deve ter este aspeto em atenção.

**Ajuda2:** planeie primeiro as classes e a interação entre elas antes de fazer código.

No final do exercício deverá ter
*   Aprendido a lidar com situações de inclusão (.h) circular e de como resolver essas situações.
*   Aprendido a lidar com situações em que uma coleção pode mudar inesperadamente enquanto é percorrida.
*   Consolidado os conceitos de herança e polimorfismo em cenários de composição. Esta descrição genérica abrange tudo o que está para trás em exercícios anteriores a este nesta ficha e, naturalmente, muito do que está para trás em fichas anteriores.

6. **Simulador de Aquário com peixes diversos – definitivamente TPC**
Pegue no exercício anterior e complete os seguintes 3 desafios

**Desfio 1:** atribua coordenadas (dentro do aquário) aos peixes e inclua uma interface que permita ao utilizador ver o aquário (considere um aquário “plano” - bidimensional). Use a biblioteca *ncurses*, ou outra qualquer (ou uma estratégia com um buffer auxiliar de caracteres), que permita colocar informação em coordenadas *linha*,*coluna* no ecrã para visualizar os peixes nas suas coordenadas. Mantenha os dados separados daparte do programa que interage com o utilizador (explore o padrão MVC).

**Desafio 2:** acrescente comportamento aos peixes: “a cada instante cada peixe faz algo, consoante a sua espécie”. A Carpa pode fugir se pressentir um tubarão perto e o tubarão poderá perseguir carpas ou até tubarões menores. Dotar o peixe da capacidade de se aperceber o que o rodeia é interessante e fácil de fazer.

**Desafio 3:** Adicione um mecanismo de “passagem de tempo” ao aquário de forma que o utilizador possa ordenar a passagem para o instante seguinte e ver os peixes efetuarem as respetivas ações.

**Sugestão 1:** acrescente outras espécies de peixes. Acrescente a sua interface de utilizador para permitir adicionar peixes, alimentar, etc.

ISEC/DEIS – Engenharia Informática
Programação Orientada a Objetos - 25/26
&lt;page_number&gt;9 / 10&lt;/page_number&gt;

---


## Page 10

No final das sugestões e desafios: parabéns – construiu um simulador de aquário.

No final do exercício deverá ter

*   Consolidado os conceitos de herança e polimorfismo em cenários de composição
*   Percebido que C++ e programação orientada a objetos facilitam bastante a construção de programas que se fossem feitos em estilo-C seriam muito mais complexos de fazer.

ISEC/DEIS – Engenharia Informática
Programação Orientada a Objetos - 25/26
&lt;page_number&gt;10 / 10&lt;/page_number&gt;