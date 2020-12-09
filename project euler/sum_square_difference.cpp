#include <iostream>
using namespace std;

int suma_2(int n){
	return (n * (n + 1) * (2*n + 1))/6;
}

int suma(int n){
	return (n * (n + 1))/2;
}

int main() {
	int n = 100;
	int a = suma(n), b = suma_2(n);
	int rta = abs((a*a)-b);
	cout << rta;
	return 0;
}