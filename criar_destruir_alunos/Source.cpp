#include <iostream>
using namespace std;

void inscricao(int b);
class aluno {
public:
	char nome[40];
	int numero;
}a;

void inscricao(int b) {
	aluno a[b];
	for	(int k = 1; k <= b; k++) {
		cout << "Nome do aluno numero " << k << ": ";
		cin >> a[k].nome;
	}
	system("pause"); system("cls");
	cout << "\tLISTA DOS ALUNOS INSCRITOS :	\n";
	for	(int k = 1; k <= b; k++) {
		cout << "Nome: " << a[k].nome << '\t';
		cout << "Numero: " << k << '\n';
	}
}

int main() {
	int j;
	cout << "Quantos alunos deseja que se matem? \n";
	cin >> j;
	inscricao(j);
}