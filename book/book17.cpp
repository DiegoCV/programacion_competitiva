#include <iostream>
using namespace std;

int main() {
	int max = 1e9 + 1;
	int n, a, b, cant_max = 0, times[max];
	cin >> n;
	while(n){
		cin >> a >> b;
		for(int i = a; i <= b; i = i + 1){
			times[i] = times[i] + 1;
			if(times[i] > cant_max) cant_max = times[i];
		}
		n = n - 1;
	}
	cout << cant_max << "\n";
	return 0;
}