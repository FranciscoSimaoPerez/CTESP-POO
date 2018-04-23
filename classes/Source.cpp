#include <iostream>
#include <string>
using namespace std;

int not_main() {
	/*class pessoa {
		public:
			char nome[40];
			int idade;
	}p1;
	strcpy_s(p1.nome, "Ana Cruz");
	p1.idade = 16;
	cout << "Nome: " << p1.nome << '\t';
	cout << "idade: " << p1.idade << '\n';
	system("Pause");*/
	class empregado {
	private: 
		char *codigo;
		float salario;
	public:
		char nome[40];
		int idade;
		void setcodigo(char *c) {
			codigo = c;
		}
		void setsalario(float s) {
			salario = s;
		}
		int *getcodigo(){
			return codigo;
		}
		int getsalario() {
			return salario;
		}
		void mostradados();//prototipo
		void empregado::mostradados() {
			cout << "Nome:" << nome << '/t';
			cout << "Idade:" << idade << '\n';
			cout << "Codigo: " << getcodigo() << '/t';
			cout << "salario: " << getsalario() << '\n';
			system("pause");
		}
	}e1;
	return 0;
}



int main() {
	not_main();
	return 0;
}