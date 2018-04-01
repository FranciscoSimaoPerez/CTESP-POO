#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

bool turno = false;
bool vitoria = false;
int opcao, posicao, turnoDesejado;
char jogador;
string valores[3][3] = { {"1", "2","3"}, {"4", "5", "6"}, {"7","8","9"} };
const char grelha[11] = {185,186,187,188,200,201,202,203,204,205,206};

int mostraGrelha(){
	system("CLS");
	cout << "---------- Jogo do Galo ----------" << endl;
	cout << "           " << grelha[5] << grelha[9] << grelha[9] << grelha[9] << grelha[7] << grelha[9] << grelha[9] << grelha[9] << grelha[7] << grelha[9] << grelha[9] << grelha[9] << grelha[2] << endl;
	cout << "           " << grelha[1] << " " << valores[0][0] << " " << grelha[1] << " " << valores[0][1] << " " << grelha[1] << " " << valores[0][2] << " " << grelha[1] << endl;
	cout << "           " << grelha[8] << grelha[9] << grelha[9] << grelha[9] << grelha[10] << grelha[9] << grelha[9] << grelha[9] << grelha[10] << grelha[9] << grelha[9] << grelha[9] << grelha[0] << endl;
	cout << "           " << grelha[1] << " " << valores[1][0] << " " << grelha[1] << " " << valores[1][1] << " " << grelha[1] << " " << valores[1][2] << " " << grelha[1] << endl;
	cout << "           " << grelha[8] << grelha[9] << grelha[9] << grelha[9] << grelha[10] << grelha[9] << grelha[9] << grelha[9] << grelha[10] << grelha[9] << grelha[9] << grelha[9] << grelha[0] << endl;
	cout << "           " << grelha[1] << " " << valores[2][0] << " " << grelha[1] << " " << valores[2][1] << " " << grelha[1] << " " << valores[2][2] << " " << grelha[1] << endl;
	cout << "           " << grelha[4] << grelha[9] << grelha[9] << grelha[9] << grelha[6] << grelha[9] << grelha[9] << grelha[9] << grelha[6] << grelha[9] << grelha[9] << grelha[9] << grelha[3] << endl;
	return 0;
}	

int jogo() {
	system("CLS");
	cout << "---------- Jogo do Galo ----------" << endl;
	cout << "Novo jogo:" << endl;
	cout << "1 - Um jogador \n";
	cout << "2 - Dois Jogadores \n";
	cout << "Escolha 1 opcao: ";
	do {
		cin >> opcao;
		if (opcao == 1) {
			cout << "Escolheu jogar so um jogador \n";
		}
		else if (opcao == 2) {
			cout << "Escolheu jogar com dois jogadores \n";
		}
		else {
			cout << "Introduza uma opcao valida \n";
		}
	} while (opcao != 1 && opcao != 2);
	
	if (opcao == 1) {
		system("CLS");
		cout << "---------- Jogo do Galo ----------" << endl;
		cout << "Deseja ser o primeiro(1) ou segundo(2) a jogar? ";
		do {
			cin >> turnoDesejado;
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
		mostraGrelha();

		while (vitoria == false) {
			if (turno == true){
				cout << "Selecione a posicao desejada: ";
				cin >> posicao;
				switch (posicao) {
				case 1: 
					valores[0][0] = jogador;
					turno = false;
					mostraGrelha();
					break;
				case 2:
					valores[0][1] = jogador;
					turno = false;
					mostraGrelha();
					break;
				case 3:
					valores[0][2] = jogador;
					turno = false;
					mostraGrelha();
					break;
				case 4:
					valores[1][0] = jogador;
					turno = false;
					mostraGrelha();
					break;
				case 5:
					valores[1][1] = jogador;
					turno = false;
					mostraGrelha();
					break;
				case 6:
					valores[1][2] = jogador;
					turno = false;
					mostraGrelha();
					break;
				case 7:
					valores[2][0] = jogador;
					turno = false;
					mostraGrelha();
					break;
				case 8:
					valores[2][1] = jogador;
					turno = false;
					mostraGrelha();
					break;
				case 9:
					valores[2][2] = jogador;
					turno = false;
					mostraGrelha();
					break;
				default:
					cout << "Escolheu uma opcao invalida \n";
					break;
				}
			}
			else if (turno == false) {
				if ()
			}
		}
	}

	return 0;
}
