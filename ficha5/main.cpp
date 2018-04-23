#include <iostream>
#include <string>


using namespace std;

int ex1() {
	string palavra;
	cout << "Digite uma palavra: ";
	cin >> palavra;
	if (palavra.length() < 5 && palavra.length() > 0) {
		cout << "Palavra pequena!\n";
	}
	else if (palavra.length() < 9) {
		cout << "Palavra media!\n";
	}
	else {
		cout << "Palavra grande!!\n";
	}
	return 0;
}

int ex2() {
	string palavra;

	int tamanho = 0;
	cout << "Digite uma palavra: ";
	cin >> palavra;
	tamanho = sizeof(palavra);
	for (int i = tamanho; i > 0; i--) {

	}
	return 0;

}

int ex3_1(int n1, int n2) {
	int resultado = n1 / n2;
	return resultado;
}

int ex3_2(int n1, int n2) {
	int resultado = n1 % n2;
	return resultado; 
}

int ex3() {
	int num1, num2;
	cout << "Insira dois numeros: ";
	cin >> num1;
	cin >> num2;
	cout << "Divisao: " << ex3_1(num1, num2) << "\n";
	cout << "Resto: " << ex3_2(num1, num2) << "\n";
	return 0;
}

int ex4() {

	return 0;
}

int main() {
	ex3();
	return 0;
}