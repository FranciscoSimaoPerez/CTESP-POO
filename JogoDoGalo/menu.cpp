#include <iostream>
#include "Header.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // Serve para poder utilizar sleep_for, sleep_until
using namespace std::chrono; // Serve para poder usar estas medidas de tempo nanoseconds, system_clock, seconds
using namespace std;

int novoJogoMenu() {
	int opcao;
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
			sleep_until(system_clock::now() + 2s);
			jogo(1);
		}
		else if (opcao == 2) {
			cout << "Escolheu jogar com dois jogadores \n";
			sleep_until(system_clock::now() + 2s);
			jogo(2);
		}
		else {
			cout << "Introduza uma opcao valida \n";
		}
	} while (opcao != 1 && opcao != 2);
	return 0;
}
int menu() {
	int opcao = 0;
	do {
		system("CLS");
		cout << "---------- Jogo do Galo ----------" << endl;
		cout << "Menu:" << endl;
		cout << "1 - Novo Jogo" << endl;
		cout << "2 - Sair " << endl;
		cout << "Escolha uma opcao valida: ";
		cin >> opcao;
		switch (opcao) {
		case 1:
			system("CLS");
			novoJogoMenu();
			break;
		case 2:
			system("CLS");
			cout << "Escolheu sair" << endl;
			break;
		default:
			system("CLS");
			cout << "Opcao Invalida!" << endl;
			break;
		}
	} while (opcao != 1 && opcao != 2);
	return 0;
}