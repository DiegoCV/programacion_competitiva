#include <iostream>
using namespace std;

int main() {
	long long maximo = 0, aux;
	int n = 20;
	int grid[n][n], i, j;

	for (i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			cin >> grid[i][j];

	for (i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(j + 3 < n){
				aux = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];				
				maximo = max(aux, maximo);
			}
			if(i + 3 < n){
				aux = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
				maximo = max(aux, maximo);
			}
			if((i + 3) < n && (j + 3) < n ){
				aux = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];				
				maximo = max(aux, maximo);	
			}
			if((i + 3) < n && (j - 3) >= 0 ){
				aux = grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
				maximo = max(aux, maximo);	
			}
		}		
	}
	cout << maximo;		
	return 0;
}