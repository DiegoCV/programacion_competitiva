#include <iostream>
using namespace std;
int main() {
	int n, count;
	cin >> n;
	for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i; 
	} 
	cout << count << "\n";
	return 0;
}