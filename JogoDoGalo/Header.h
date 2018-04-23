#pragma once
#include <iostream>

using namespace std;

int menu();
int jogo(int opcao);

class jogador {
public:
	char nome[10];
	int idade;
	int nVitorias;
	int nJogos;
	int racioVitoria;

	//M�todos
	//Cria Jogadores
	int criarJogador() {
		system("CLS");
		cout << "---------- Jogo do Galo ----------\n";
		cout << "Novo Jogador: \n";
		cout << "\n\tIntroduza o seu nome: ";
		cin >> nome;
		cout << "\n\tIntroduza a sua idade: ";
		cin >> idade;
		return 0;
	}

	//Mostra dados de Jogadores
	int mostraJogador() {
		system("CLS");
		cout << "---------- Jogo do Galo ----------\n";
		cout << "Dados Jogador: \n";
		cout << "Nome: " << nome << "\n";
		cout << "Idade: " << idade << "\n";
		cout << "Numero de vitorias: " << nVitorias << "\n";
		cout << "Racio de vitorias: " << racioVitoria << "\n";
		return 0;
	}

	//Adiciona Vit�ria
	int vitoria() {
		nVitorias++;
		nJogos++;
		racioVitoria = nVitorias / nJogos;
		return 0;
	}

	//Adiciona um jogo em caso de empate ou derrota
	int derrotaOuEmpate() {
		nJogos++;
		racioVitoria = nVitorias / nJogos;
		return 0;
	}
};
