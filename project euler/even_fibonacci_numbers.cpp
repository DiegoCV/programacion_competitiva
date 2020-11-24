#include <iostream>

using namespace std;

int main() {
	int total = 0, limit = 4e6;
	int prev = 1, next = 1, aux;
	while(next < limit){
		if(next % 2 == 0) total += next;
		aux = next;
		next = prev + next;
		prev = aux;
	}
	cout << total;
	return 0;
}