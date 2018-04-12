#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

class jogador {
	string nome;
	int idade;
	int nVitorias;
	int nJogos;
	int racioVitoria;

	public:
		//Métodos
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

		//Adiciona Vitória
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
}jogadores[50];

