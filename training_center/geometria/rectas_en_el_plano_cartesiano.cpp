#include <iostream>
using namespace std;

int main() {
	int n, x1, y1, x2, y2;
	cin >> n;
	while(n){
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1 == y2){
			cout << "Recta paralela al eje X" << "\n";
		}else if(x1 == x2){
			cout << "Recta paralela al eje Y" << "\n";
		}else{
			cout << "Recta no paralela a ningun eje" << "\n";
		}
		n--;
	}
	return 0;
}