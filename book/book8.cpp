#include <iostream>
using namespace std;

long long const MOD = 1e9 + 7; 
long long const base = 2;

long long potencia(long long exponente){
	if(exponente == 1) return base%MOD;
	if(exponente & 1){
		return ((base%MOD) * (potencia(exponente - 1)%MOD))%MOD; 		
	}else{
		long long res = potencia(exponente/2);
		return ((res%MOD) * (res%MOD))%MOD;
	} 
}
int main() {
	long long n;
	cin >> n;
	cout << potencia(n) << "\n";
	return 0;
}