#include <iostream>
#include <math.h>
using namespace std;

bool is_pitagorico(int a, int b, int c){
	int aux = pow(a,2) + pow(b,2);	
	return aux == pow(c,2);
}

int main() {
	int a = 1, b = 2, c = 997, aux;
	while(true){				
		if((a < b) && (b < c) && is_pitagorico(a,b,c)){
			break;
		}
		if(b + 1 < c){
			b++;
			c--;
		}else{
			a++;
			b = a + 1;
			c = 1000 - (a + b);
		}
	}
	cout << (a*b*c);
	return 0;
}
