#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace std::this_thread; // Serve para poder utilizar sleep_for, sleep_until
using namespace std::chrono; // Serve para poder usar estas medidas de tempo nanoseconds, system_clock, seconds

// Classe Jogador
class Jogador {
private:
	string nome;
	int vitorias;
public:
	//Construtores
	Jogador() {
		setNome(" ");
		setVitorias(0);
	}
	//Funções de Acesso
	void setNome(string n) { nome = n; }
	void setVitorias(int v) { vitorias = v; }
	
	string getNome() { return nome; }
	int getVitorias() { return vitorias; }
	
	void incrementaVitorias() {
		vitorias++;
	}
}j[2];

