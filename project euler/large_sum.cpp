#include <iostream>
#include <string.h>
using namespace std;

int main() {
	double rta = 0, aux;
	int i = 0;
	while(i < 100){		
		cin >> aux;
		rta += aux;
		i++;
	} 
	cout << to_string(rta);
	return 0;
}