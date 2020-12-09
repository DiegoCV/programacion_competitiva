#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = n / 2;
	if(n == 0 || n % 2 != 0) cout << "NO";
	else cout << "YES";
	return 0;
}