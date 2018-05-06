#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace std::this_thread; // Serve para poder utilizar sleep_for, sleep_until
using namespace std::chrono; // Serve para poder usar estas medidas de tempo nanoseconds, system_clock, seconds

class Jogador;
int menu();
int jogo(int opcao);
int main();
char pedeOpcao();