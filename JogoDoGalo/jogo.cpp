#include <iostream>
#include <string>
#include "Header.h"
#include "Jogador.h"
#include <chrono>
#include <thread>
#include <fstream>

// Falta fazer guardar score e nome do jogador no fim

using namespace std;
using namespace std::this_thread; // Serve para poder utilizar sleep_for, sleep_until
using namespace std::chrono; // Serve para poder usar estas medidas de tempo nanoseconds, system_clock, seconds

//Variáveis globais
int opcao, posicao, turnoDesejado;
int jogadaCPU[2];
char vencedor;
char jogador, jogador2, computador;//Variáveis de cada jogador (X ou O)
const char grelha[11] = {185,186,187,188,200,201,202,203,204,205,206};//Valores ASCI armazenados em array para criacao da grelha de jogo
char valores[3][3] = { { '1', '2','3' },{ '4', '5', '6' },{ '7','8','9' } };//Valores iniciais de cada posicao
string nomeJogador1, nomeJogador2;

//Funções																			
//Funcao que mostra grelha de jogo
int mostraGrelha(){
	system("CLS");
	cout << "---------- Jogo do Galo ----------\n";
	cout << "           " << grelha[5] << grelha[9] << grelha[9] << grelha[9] << grelha[7] << grelha[9] << grelha[9] << grelha[9] << grelha[7] << grelha[9] << grelha[9] << grelha[9] << grelha[2] << endl;
	cout << "           " << grelha[1] << " " << valores[0][0] << " " << grelha[1] << " " << valores[0][1] << " " << grelha[1] << " " << valores[0][2] << " " << grelha[1] << endl;
	cout << "           " << grelha[8] << grelha[9] << grelha[9] << grelha[9] << grelha[10] << grelha[9] << grelha[9] << grelha[9] << grelha[10] << grelha[9] << grelha[9] << grelha[9] << grelha[0] << endl;
	cout << "           " << grelha[1] << " " << valores[1][0] << " " << grelha[1] << " " << valores[1][1] << " " << grelha[1] << " " << valores[1][2] << " " << grelha[1] << endl;
	cout << "           " << grelha[8] << grelha[9] << grelha[9] << grelha[9] << grelha[10] << grelha[9] << grelha[9] << grelha[9] << grelha[10] << grelha[9] << grelha[9] << grelha[9] << grelha[0] << endl;
	cout << "           " << grelha[1] << " " << valores[2][0] << " " << grelha[1] << " " << valores[2][1] << " " << grelha[1] << " " << valores[2][2] << " " << grelha[1] << endl;
	cout << "           " << grelha[4] << grelha[9] << grelha[9] << grelha[9] << grelha[6] << grelha[9] << grelha[9] << grelha[9] << grelha[6] << grelha[9] << grelha[9] << grelha[9] << grelha[3] << endl;
	cout << "----------------------------------\n";
	return 0;
}	

//Funcao que calcula a jogada do computador
int* calculaJogadaCPU() {
	jogadaCPU[0] = rand() % 3;
	jogadaCPU[1] = rand() % 3;
	return jogadaCPU;
}

//Funcao que verifica se o Jogo já acabou
bool verificaJogo(char apontaValores[3][3]) {
	//Diagonais
	if ((apontaValores[0][0] == apontaValores[1][1]) && (apontaValores[1][1] == apontaValores[2][2])) {
		vencedor = apontaValores[0][0];
		return true;
	}
	else if ((apontaValores[2][0] == apontaValores[1][1]) && (apontaValores[1][1] == apontaValores[0][2])) {
		vencedor = apontaValores[1][1];
		return true;
	}
	//Verticais
	else if ((apontaValores[0][0] == apontaValores[0][1]) && (apontaValores[0][1] == apontaValores[0][2])) {
		vencedor = apontaValores[0][0];
		return true;
	}
	else if ((apontaValores[1][0] == apontaValores[1][1]) && (apontaValores[1][1] == apontaValores[1][2])) {
		vencedor = apontaValores[1][0];
		return true;
	}
	else if ((apontaValores[2][0] == apontaValores[2][1]) && (apontaValores[2][1] == apontaValores[2][2])) {
		vencedor = apontaValores[2][0];
		return true;
	}
	// Horizontais
	else if ((apontaValores[0][0] == apontaValores[1][0]) && (apontaValores[1][0] == apontaValores[2][0])) {
		vencedor = apontaValores[0][0];
		return true;
	}
	else if ((apontaValores[0][1] == apontaValores[1][1]) && (apontaValores[1][1] == apontaValores[2][1])) {
		vencedor = apontaValores[0][1];
		return true;
	}
	else if ((apontaValores[0][2] == apontaValores[1][2]) && (apontaValores[1][2] == apontaValores[2][2])) {
		vencedor = apontaValores[0][2];
		return true;
	}
	else {
		return false;
	}
}

// Funçao que reinicia os valores da grelha
int reiniciaValores() {
	char num = '0';
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			num++;
			valores[y][x] = num;
		}
	}
	return 0;
}

char pedeOpcao() {
	char opcao;
	cin >> opcao;
	opcao -= 48;
	return opcao;
}

int jogo(int opcao) {
	// Chamada da Função que reinicia o array Valores
	reiniciaValores();

	//Variáveis da função jogo
	int numeroJogadas = 0;
	char voltarMenu;
	bool turno = false;
	bool existeVencedor = false;
	vencedor = ' ';
	if (opcao == 1) {
		system("CLS");
		cout << "---------- Jogo do Galo ----------" << endl;
		cout << "Deseja ser o primeiro(1) ou segundo(2) a jogar? ";
		do {
			turnoDesejado = pedeOpcao();
			if (turnoDesejado != 1 && turnoDesejado != 2) {
				cout << "Introduza uma opcao valida: ";
			}
			else if (turnoDesejado == 1) {
				turno = true;
			}
			else if (turnoDesejado == 2) {
				turno = false;
			}
		} while (turnoDesejado != 1 && turnoDesejado != 2);
		system("CLS");
		cout << "---------- Jogo do Galo ----------" << endl;
		cout << "Deseja ser o 'X' ou o 'O'? \n";
		do {
			cin >> jogador;
			if (jogador != 'X' && jogador != 'x' && jogador != 'O' && jogador != 'o') {
				cout << "Introduza uma opcao valida: ";
			}
		} while (jogador != 'X' && jogador != 'x' && jogador != 'O' && jogador != 'o');
		jogador = toupper(jogador);
		cout << "Escolheu ser o '" << jogador << "'! \n";
		sleep_until(system_clock::now() + 2s);
		if (jogador == 'X')
		{
			computador = 'O';
		}
		else
		{
			computador = 'X';
		}
		mostraGrelha();
		cout << "Boa Sorte! \n";
		sleep_until(system_clock::now() + 3s);

		while (existeVencedor == false && numeroJogadas < 9) {
			mostraGrelha();
			if (turno == true) {
				cout << "Selecione a posicao desejada: ";
				switch (pedeOpcao()) {
				case 1:
					if (valores[0][0] != 'X' && valores[0][0] != 'O') {
						valores[0][0] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				case 2:
					if (valores[0][1] != 'X' && valores[0][0] != 'O') {
						valores[0][1] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				case 3:
					if (valores[0][2] != 'X' && valores[0][2] != 'O') {
						valores[0][2] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				case 4:
					if (valores[1][0] != 'X' && valores[1][0] != 'O') {
						valores[1][0] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				case 5:
					if (valores[1][1] != 'X' && valores[1][1] != 'O') {
						valores[1][1] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				case 6:
					if (valores[1][2] != 'X' && valores[1][2] != 'O') {
						valores[1][2] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				case 7:
					if (valores[2][0] != 'X' && valores[2][0] != 'O') {
						valores[2][0] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				case 8:
					if (valores[2][1] != 'X' && valores[2][1] != 'O') {
						valores[2][1] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				case 9:
					if (valores[2][2] != 'X' && valores[2][2] != 'O') {
						valores[2][2] = jogador;
						turno = false;
						mostraGrelha();
						numeroJogadas++;
						existeVencedor = verificaJogo(valores);
					}
					break;
				default:
					cout << "Escolheu uma opcao invalida \n";
					break;
				}
			}
			else if (turno == false) {
				//Jogada do Computador
				int *jogada = calculaJogadaCPU();
				while (valores[jogada[0]][jogada[1]] == 'X' || valores[jogada[0]][jogada[1]] == 'O') {
					int *jogada = calculaJogadaCPU();
				}
				valores[jogada[0]][jogada[1]] = computador;
				turno = true;
				mostraGrelha();
				numeroJogadas++;
				existeVencedor = verificaJogo(valores);
			}
		}
		if ((vencedor == 'X' && jogador == 'X') || (vencedor == 'O' && jogador == 'O')) {
			cout << "Parabens ganhou o jogo! \n";
			sleep_until(system_clock::now() + 3s);
		}
		else if ((vencedor == 'X' && jogador != 'X') || (vencedor == 'O' && jogador != 'O')) {
			cout << "Perdeu o jogo contra o computador! \n";
			sleep_until(system_clock::now() + 3s);
		}
		else {
			cout << "Jogo terminou empatado! \n";
			sleep_until(system_clock::now() + 3s);
		}
		cout << "Deseja voltar ao menu?(S ou N) \n";
		do {
			cin >> voltarMenu;
			if (voltarMenu != 'S' && voltarMenu != 's' && voltarMenu != 'N' && voltarMenu != 'n') {
				cout << "Introduza uma opcao valida: ";
			}
		} while (voltarMenu != 'S' && voltarMenu != 's' && voltarMenu != 'N' && voltarMenu != 'n');
		if (voltarMenu == 'S' || voltarMenu == 's') {
			menu();
		}
		return 0;
	}
	else if (opcao == 2) {
		//Multijogador 
		//Será pedido os nomes dos jogadores caso seja o primeiro jogo, caso contrário é usado os nomes anteriores
		system("CLS");
		cout << "---------- Jogo do Galo ----------" << endl;
		while (j[0].getNome() == " " && j[1].getNome() == " "){
			cout << "Introduza o nome do Jogador 1(sem espacos): ";
			cin >> nomeJogador1;
			cout << "Introduza o nome do Jogador 2(sem espacos): ";
			cin >> nomeJogador2;
			j[0].setNome(nomeJogador1);
			j[1].setNome(nomeJogador2);
		}
		cout << "Pontuacao de " << j[0].getNome() << ": " << j[0].getVitorias() << "!\n";
		cout << "Pontuacao de " << j[1].getNome() << ": " << j[1].getVitorias() << "!\n";
		sleep_until(system_clock::now() + 5s);
		mostraGrelha();
		cout << j[0].getNome() << " sera 'X' e " << j[1].getNome() << " sera 'O' \n";
		cout << "Boa Sorte e que ganhe o melhor!";
		sleep_until(system_clock::now() + 3s);
		mostraGrelha();
		//Jogo 
		//Ciclo while que repete até que chegue ao total de 9 jogadas ou exista um vencedor
		while (existeVencedor == false && numeroJogadas < 9) {
			if (numeroJogadas % 2 == 0) {
				jogador = 'X';
				cout << "Turno do " << j[0].getNome() << " \n";
			}
			else {
				jogador = 'O';
				cout << "Turno do " << j[1].getNome() << " \n";
			}
			cout << "Selecione a posicao desejada: ";
			switch (pedeOpcao()) {
				case 1:
					if (valores[0][0] != 'X' && valores[0][0] != 'O') {
						valores[0][0] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				case 2:
					if (valores[0][1] != 'X' && valores[0][1] != 'O') {
						valores[0][1] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				case 3:
					if (valores[0][2] != 'X' && valores[0][2] != 'O') {
						valores[0][2] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				case 4:
					if (valores[1][0] != 'X' && valores[1][0] != 'O') {
						valores[1][0] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				case 5:
					if (valores[1][1] != 'X' && valores[1][1] != 'O') {
						valores[1][1] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				case 6:
					if (valores[1][2] != 'X' && valores[1][2] != 'O') {
						valores[1][2] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				case 7:
					if (valores[2][0] != 'X' && valores[2][0] != 'O') {
						valores[2][0] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				case 8:
					if (valores[2][1] != 'X' && valores[2][1] != 'O') {
						valores[2][1] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				case 9:
					if (valores[2][2] != 'X' && valores[2][2] != 'O') {
						valores[2][2] = jogador;
						mostraGrelha();
						existeVencedor = verificaJogo(valores);
						numeroJogadas++;
					}
					break;
				default:
					cout << "Escolheu uma opcao invalida \n";
					break;
			}
		}
		//Verifica Vencedor e Incrementa Número de Vitórias
		if (vencedor == 'X' && jogador == 'X') {
			cout << "O jogador " << j[0].getNome() << " ganhou o jogo! \n";
			j[0].incrementaVitorias();
			sleep_until(system_clock::now() + 3s);
		}
		else if (vencedor == 'O' && jogador == 'O') {
			cout << "O jogador " << j[1].getNome() << " ganhou o jogo! \n";
			j[1].incrementaVitorias();
			sleep_until(system_clock::now() + 3s);
		}
		else {
			cout << "Jogo terminou empatado! \n";
			sleep_until(system_clock::now() + 3s);
		}
		// Pergunta se deseja voltar ao menu principal
		cout << "Deseja voltar ao menu?(S ou N) \n";
		do {
			cin >> voltarMenu;
			if (voltarMenu != 'S' && voltarMenu != 's' && voltarMenu != 'N' && voltarMenu != 'n') {
				cout << "Introduza uma opcao valida: ";
			}
		} while (voltarMenu != 'S' && voltarMenu != 's' && voltarMenu != 'N' && voltarMenu != 'n');
		if (voltarMenu == 'S' || voltarMenu == 's') {
			menu();
		}
	}
	return 0;
}