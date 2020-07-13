#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, x, i;
  cin >> n >> x;
  vector<int> pi(n);
  for (i = 0; i < n; i++) cin >> pi[i];
  sort(pi.begin(), pi.end());
  i = 0;
  int j = n-1, c = 0;
  while(i <= j){
  	if(i == j){
  		if(pi[i] <= x) c++;
  		break;
  	}
  	if(pi[j] > x) j--;	
  	if(pi[i] > x) i++;
  	if(pi[i] + pi[j] <= x){
  		i++; j--; c++;
  	}else{
  		j--;
  		c++;
  	}
  }
  cout << c;
}