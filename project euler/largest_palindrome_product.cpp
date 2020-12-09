#include <iostream>
using namespace std;

int revertir(int x){
	int aux = 0;
	while(x > 0){
		aux = aux * 10 + (x % 10);
		x = x / 10;
	}	
	return aux;
}

bool is_palindromo(int x){	
	return x == revertir(x);
}

int main() {
	int maximo = 0;
	for(int i = 100; i <= 999; i++){
		for(int j = i; j <= 999; j++){
			if(is_palindromo(i*j)){
				maximo = max(maximo, (i*j));
			}
		}		
	}
	cout << maximo;
	return 0;
}