#include <iostream>
#include <string>
using namespace std;

float get_nota_1();
float get_nota_2();

class aluno {
public:
	char nome[15];
	int numero_do_aluno;
	float nota_1, nota_2;

}a1;

int main() {
	cout << "Introduza o nome: ";
	cin >> a1.nome;
	cout << "Introduza o numero de aluno: ";
	cin >> a1.numero_do_aluno;
	cout << "Introduza a nota 1 teste: ";
	cin >> a1.nota_1;
	cout << "Introduza a nota 2 teste: ";
	cin >> a1.nota_2;
	system("CLS");
	
	//cout << "Nota final do " << a1.nome << ": " << a1.nota_final() << endl;
	return 0;
}