#include "Agenda.h"
#include <iostream>
#include <sstream>

// =============================================================================
// INSERIR CONTACTO NO MAP
// =============================================================================
// MAP: Associa KEY (nome) ? VALUE (Contacto)
// insert() retorna std::pair<iterator, bool>
//   - pair.first = iterador para o elemento (novo ou existente)
//   - pair.second = true se INSERIU, false se JÁ EXISTIA
// =============================================================================
bool Agenda::insere(string nome, string morada, int tel) {
	// insert({ key, value }) tenta inserir novo par no map
	// Se a KEY já existe, NÃO insere e retorna false no .second
	auto resultado = contactos.insert({ nome, Contacto(nome, morada, tel) });
	
	// Retorna true se inseriu, false se nome já existia
	return resultado.second;
}

// =============================================================================
// ELIMINAR CONTACTO DO MAP POR NOME (KEY)
// =============================================================================
// MAP: Busca O(log n) com find()
// erase() remove o elemento apontado pelo iterador
// =============================================================================
bool Agenda::elimina(string nome) {
	// find(key) procura pela KEY no map
	// Retorna iterador para o elemento ou end() se não encontrou
	auto it = contactos.find(nome);
	
	// it != end() significa que ENCONTROU o contacto
	if (it != contactos.end()) {
		// erase(iterador) remove o elemento do map
		contactos.erase(it);
		return true;  // Sucesso: contacto eliminado
	}
	
	return false;  // Falha: contacto não encontrado
}

// =============================================================================
// OBTER TELEFONE DE UM CONTACTO POR NOME (KEY)
// =============================================================================
// MAP: iterador aponta para std::pair<const string, Contacto>
//   - it->first  = KEY (string nome) - CONST, não pode modificar
//   - it->second = VALUE (Contacto) - pode modificar (mas não aqui, pois const)
// =============================================================================
int Agenda::obtemTelefone(string nome) const {
	// Busca o contacto pela KEY (nome)
	auto it = contactos.find(nome);
	
	if (it != contactos.end()) {  // Encontrou?
		// it->second acede ao VALUE (objeto Contacto)
		// getTelef() retorna o telefone do contacto
		return it->second.getTelef();
	}
	else {
		// -1 indica "não encontrado" (telefones válidos são positivos)
		return -1;
	}
}

// =============================================================================
// OBTER MORADA DE UM CONTACTO POR NOME (KEY)
// =============================================================================
string Agenda::obtemMorada(string nome)const {
	std::ostringstream oss;  // Buffer para construir string
	
	// Busca o contacto pela KEY (nome)
	auto it = contactos.find(nome);
	
	if (it != contactos.end()) {  // Encontrou?
		// it->second = VALUE (Contacto)
		// getMorada() retorna a morada como string
		oss << it->second.getMorada() << std::endl;
		return oss.str();  // Retorna morada + quebra de linha
	}
	
	// String vazia indica "não encontrado"
	return "";
}

// =============================================================================
// ATUALIZAR TELEFONE DE UM CONTACTO EXISTENTE
// =============================================================================
// MAP: VALUE (Contacto) é modificável, mas KEY (nome) é CONST!
// Por isso podemos chamar mudaTelef() diretamente no it->second
// =============================================================================
bool Agenda::atualizaTelefone(string nome, int tel) {
	// Busca o contacto pela KEY (nome)
	auto it = contactos.find(nome);
	
	if (it != contactos.end()) {  // Encontrou?
		// it->second = VALUE (Contacto) - MODIFICÁVEL!
		// mudaTelef() altera o telefone do contacto no map
		it->second.mudaTelef(tel);
		return true;  // Sucesso
	}
	
	return false;  // Falha: contacto não encontrado
}

// =============================================================================
// ATUALIZAR MORADA DE UM CONTACTO EXISTENTE
// =============================================================================
bool Agenda::atualizaMorada(string nome, string morada) {
	// Busca o contacto pela KEY (nome)
	auto it = contactos.find(nome);
	
	if (it != contactos.end()) {  // Encontrou?
		// it->second = VALUE (Contacto) - modificável
		// mudaMorada() altera a morada do contacto
		it->second.mudaMorada(morada);
		return true;  // Sucesso
	}
	
	return false;  // Falha: contacto não encontrado
}

// =============================================================================
// ATUALIZAR NOME (KEY) DE UM CONTACTO
// =============================================================================
// MAP: KEY é CONST - NÃO pode ser modificada diretamente!
// Solução: REMOVER contacto antigo + INSERIR novo com mesmos dados
// Cuidado: Verificar se nomeNovo já existe para evitar conflitos
// =============================================================================
bool Agenda::atualizaNome(string nomeAntigo, string nomeNovo) {
	// 1. Procurar contacto com nomeAntigo
	auto it = contactos.find(nomeAntigo);
	
	if (it != contactos.end()) {  // nomeAntigo existe?
		// 2. Verificar se nomeNovo JÁ EXISTE (evitar conflito!)
		auto it2 = contactos.find(nomeNovo);
		
		if (it2 == contactos.end()) {  // nomeNovo NÃO existe? (está livre)
			// 3. Guardar dados do contacto antigo
			string morada = it->second.getMorada();
			int telefone = it->second.getTelef();
			
			// 4. REMOVER contacto com nomeAntigo
			contactos.erase(it);
			
			// 5. INSERIR novo contacto com nomeNovo (mesmos dados)
			contactos.insert({ nomeNovo, Contacto(nomeNovo, morada, telefone) });
			
			return true;  // Sucesso
		}
		
		return false;  // Falha: nomeNovo já existe (conflito!)
	}
	
	return false;  // Falha: nomeAntigo não encontrado
}

// =============================================================================
// OBTER LISTA DE TODOS OS CONTACTOS
// =============================================================================
// MAP: Percorre TODOS os elementos com iteradores
// Elementos estão ORDENADOS automaticamente pela KEY (nome alfabético)
// Cada iterador aponta para std::pair<const string, Contacto>
// =============================================================================
string Agenda::obtemLista() const {
	std::ostringstream oss;  // Buffer para construir string
	
	// Percorre TODOS os contactos do início ao fim
	for (auto it = contactos.begin(); it != contactos.end(); it++) {
		// it->first  = KEY (nome do contacto)
		// it->second = VALUE (objeto Contacto)
		// descricao() retorna: "nome morada telefone"
		oss << it->second.descricao() << std::endl;
	}
	
	// Retorna string com todos os contactos (um por linha)
	return oss.str();
}