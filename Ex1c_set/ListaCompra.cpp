#include "ListaCompra.h"

// =============================================================================
// DIFERENÇAS ENTRE ARRAY, VECTOR E SET:
// 
// ARRAY (Ex1a):
//   - Tamanho FIXO definido na declaração (ex: 20)
//   - Precisa de "int quantos" para saber quantos estão ocupados
//   - Adicionar: coisas[quantos] = Coisa(...); quantos++;
//   - Remover: coisas[i] = coisas[quantos-1]; quantos--;
//   - Precisa de construtor Coisa() default
//   - Ordem: Manual (ordem de inserção)
//   - Acesso: O(1) direto por índice
//
// VECTOR (Ex1b):
//   - Tamanho VARIÁVEL, cresce e diminui automaticamente
//   - Usa coisas.size() para saber o tamanho
//   - Adicionar: coisas.push_back(Coisa(...));
//   - Remover: coisas[i] = coisas.back(); coisas.pop_back();
//   - NAO precisa de construtor default
//   - Ordem: Manual (ordem de inserção)
//   - Acesso: O(1) direto por índice
//
// SET (Ex1c) - ORDENAÇÃO AUTOMÁTICA:
//   - Tamanho VARIÁVEL, sem limite predefinido
//   - Usa coisas.size() para saber o tamanho
//   - Adicionar: coisas.insert(Coisa(...));
//   - Remover: coisas.erase(it);
//   - NÃO precisa de construtor default
//   - EXIGE operator< na classe Coisa (para ordenação)
//   - Ordem: AUTOMÁTICA (alfabética pelo nome neste caso)
//   - NÃO permite duplicados (chave única)
//   - Busca: O(log n) eficiente com find()
//   - Acesso: NÃO tem operator[], precisa de iteradores
//   - Elementos são CONST (imutáveis) - para modificar: remover e reinserir
//   - Implementação: Árvore balanceada (Red-Black Tree)
//
// QUANDO USAR SET:
//   ? Precisa de ordenação automática
//   ? Precisa de busca rápida O(log n)
//   ? Não quer duplicados
//   ? Precisa de acesso por índice (use vector)
//   ? Precisa modificar elementos (use vector ou map)
// =============================================================================

bool ListaCompra::adiciona(string nome, int qty) {
    Coisa temp(nome, 0);
    auto it = coisas.find(temp);

    if (it != coisas.end()) {
        //se não chegar ao final, quer dizer que encontrei
        Coisa nova(nome, it->getQty() + qty);
        coisas.erase(it);
        coisas.insert(nova);
    }
    else {
        coisas.insert(Coisa(nome, qty));
    }
    return true;
}

bool ListaCompra::removeQty(string nome, int qty) {
    Coisa temp(nome, 0);
    auto it = coisas.find(temp);

    if (it != coisas.end()) {
        //Se não chegar ao final, quer dizer que encontrei
        Coisa nova(nome, it->getQty() - qty);
        coisas.erase(it); //faz sentido pois o it agora é o objeto Coisa em questão, aquele pode ser removido, porque não dá para alterar e temos que sempre apagar e voltar a inserir a nova.
        if (nova.getQty() > 0) {
            coisas.insert(nova);
        }
        return true;
    }
    return false;
}

bool ListaCompra::elimina(string nome) {
    Coisa temp(nome, 0); //Cria temporário para busca
    auto it = coisas.find(temp); //Busca no set

    if (it != coisas.end()) { //Encontrou?
        //significa que não chegou ao final quer dizer que encontrou
        coisas.erase(it); //Remove do set
        return true;
    }
    return false; //Não encontrou
}

int ListaCompra::eliminaTodosMenoresQue(int qty) {
    int contador = 0;
    
    for (auto it = coisas.begin(); it != coisas.end();) {
        if (it->getQty() < qty) {
            it = coisas.erase(it); //SET: erase () retorna próximo iterador válido
            contador++;
        }
        else {
            it++;
        }
    }
    return contador;
}

string ListaCompra::obtemDescricao() const {
    std::ostringstream oss;
    for (auto it = coisas.begin(); it != coisas.end(); it++) {
        oss << it->descricao() << std::endl;
    }
    return oss.str();
}

Coisa ListaCompra::obtemAt(int posicao) {
    if (posicao >= 0 && posicao < coisas.size()) {
        auto it = coisas.begin();         // Começa no início
        for (int i = 0; i < posicao; i++) {
            ++it;                         // Avança manualmente, passo a passo
        }
        return *it;                       // Retorna o elemento
    }
    else {
        throw std::invalid_argument("Posicao invalida");
    }
}
