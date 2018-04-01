#include <iostream>
#include "Header.h"
using namespace std;
int menu() {
	int opcao = 0;
	do {
		system("CLS");
		cout << "---------- Jogo do Galo ----------" << endl;
		cout << "Menu:" << endl;
		cout << "1 - Novo Jogo" << endl;
		cout << "2 - Sair " << endl;
		cout << "Escolha uma opcao valida:";
		cin >> opcao;
		switch (opcao) {
		case 1:
			system("CLS");
			
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