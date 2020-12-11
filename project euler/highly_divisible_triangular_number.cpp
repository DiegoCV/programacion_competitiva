#include <iostream>
#include <vector>
#include <utility> 
#include <cmath>
using namespace std;

vector<int> criba_eratostenes(int n){
    vector<int> criba;
    int current_primo;  // numero primo que iremos tomando del vector

    // vector con numeros desde 2 hasta n
    for (int i = 2; i <= n; i++)
        criba.push_back(i);
        
    if (n == 2 || n == 3) 
        return criba;

    // iterador para el vector criba
    vector<int>::iterator it = criba.begin();

    current_primo = *it;  // El primer primo es el 2

    do
    {
        vector<int>::iterator it2 = it + 1;

        for(; it2 <= criba.end(); it2++)
            if(*it2 % current_primo == 0)
                criba.erase(it2);

        it++;
        current_primo = *it;

    } while (pow(current_primo, 2) < n);

    return criba;
}

vector<int> numeros_primos;


int get_triangle_number(int n){
	return (n*(n+1))/2;
}

vector<pair<int, int>> descomponer_factores_primos(int n){
	vector<pair<int, int>> factores_primos;
	int i = 0, j = 0;	
	while(n > 1){
		if(n % numeros_primos[i] == 0){
			j++;
			n = n / numeros_primos[i]; 
			if(n == 1){
				pair<int, int> factor(numeros_primos[i],j);  				
				factores_primos.push_back(factor);
			}
		}else{
			if(j > 0 ){
				pair<int, int> factor(numeros_primos[i],j);  				
				factores_primos.push_back(factor);
			} 
			j = 0;
			i++;
		}
	}
	return factores_primos;
}

int get_total_divisores(int n){
	int total = 1;
	vector<pair<int, int>> factores_primos;
	factores_primos = descomponer_factores_primos(n);
	for (int i = 0; i < factores_primos.size(); i++)
        total *= factores_primos[i].second + 1;
	return total;
}

int main() {
	int maximo = 500;
	numeros_primos = criba_eratostenes(100000);
	int n = 1;
	int numero_triangular = 1;
	while(get_total_divisores(numero_triangular) < maximo){
		n++;
		numero_triangular = get_triangle_number(n);
	}
	cout << numero_triangular << endl;
}