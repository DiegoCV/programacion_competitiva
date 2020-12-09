#include <iostream>
#include<climits> 
using namespace std;

int main() {
	int n, i;
	long long max_so_far = LLONG_MIN, max_ending_here = 0; 
	cin >> n;
	long long a[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
    for (i = 0; i < n; i++) { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    cout << max_so_far; 
	return 0;
}