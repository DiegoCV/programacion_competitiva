#include <iostream>
using namespace std;

int const mayor = 5e8;
int dp[mayor];

bool is_par(int i){
	int f = i % 2;
	return f == 0;
}

long long total_collatz(long long i){
	long long total = 0;
	while(true){			
		if(is_par(i)){
			i = i/2;			
		}else{
			i = (3*i)+1;
		}
		total++;
		if(i == 1){
			total ++;
			break;
		}			
	}		
	return total;
}

int main() {
	long long rta = -1, indice = -1, aux;
	for (long long i = 999999; i > 1; i--){
		aux = total_collatz(i);		
		if(aux > rta){
			rta = aux;
			indice = i;	
		}
	}	
	cout << rta << " - " << indice << endl;		
	return 0;
}


