#include <iostream>
#include <string>
#include "Header.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	menu();
	cin.sync(); // Flush The Input Buffer Just In Case
	cin.ignore(); // There's No Need To Actually Store The Users Input
	return 0;
}