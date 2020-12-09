#include <iostream>
using namespace std;

int main() {
	int n, m, max, total, aux_int;
	while(cin>>n>>m){
		max = 0;
		total = 0;
		for(int i = 0; i < n; i = i + 1){
			cin>>aux_int;
			total = total + aux_int;
			if(total < 0){
				max = max + abs(total);
				total = 0;
			}
		}
		cout<<max<<" "<<m+max-total<<endl;
	}
	return 0;
}