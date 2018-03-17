/*
 * main.cpp
 *
 *  Created on: 11/03/2018
 *      Author: Francisco
 */

#include <iostream>
using namespace std;

void ex2(){
	int num1, num2, res;
		do {
			cout << "Introduza dois numero inteiros: 1- ";
			cin >> num1;
			cout << "2- ";
			cin >> num2;
			res = num1 * num2;
			cout << num1 << " * " << num2 << " = " << res << endl;
		} while(res <=1000 && res >=10);
}

int ex4(){
	int vetor[5];
	cout << "Introduza 5 valores" << endl;
	for (int i = 0; i < 5; i++){
		cout << "Indique o valor para v[" << i << "]: ";
		cin >> vetor[i];
	}
	for (int x = 4; x >= 0; x--){
		cout << "vetor[" << x << "]="<< vetor[x] << endl;
	}
	return 0;
}

int main(){
	int opcao;
	cout << "Introduza o número do exercicio: ";
	cin >> opcao;
	switch(opcao){
	case 2:
		ex2();
		break;
	case 4:
		ex4();
		break;

	default:
		cout << "Exxercicio inexistente!";
	}
	return 0;
}




