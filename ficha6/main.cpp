#include <iostream>

using namespace std;

class Produto {
	float valor;
public:
	void atribui(float v) { valor = v; }
	void escreve() {
		cout << valor << endl;
	}
};

void valor_venda(Produto v) {
	v.escreve();//escreve 10
	v.atribui(20); //localmente(alteração apenas local)
	v.escreve();//escreve 10
}

int main() {
	Produto v1;
	v1.atribui(10); //Atribui 10 ao valor de v1
	valor_venda(v1); //Passa o valor v1 para a função
	v1.escreve();
	return 0;
}