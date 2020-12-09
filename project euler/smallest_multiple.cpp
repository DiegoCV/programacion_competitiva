#include <iostream>
using namespace std;

int main() {
	int n = 1;
	while(true){
		int j = 1;
		for(int i = 2; i <= 20; i++){
			if( n % i == 0){
				j++;
			}else{
				break;
			}
		}
		if(j == 20) break;
		n++;
	}
	cout << n;
	return 0;
}