#include <iostream>
using namespace std;

int main() {
	int n,q,aux, aux1, aux2;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i = i + 1){
		cin>>arr[i];
	}
	cin>>q;
	for(int i = 0; i < q; i = i + 1){
		cin>>aux>>aux1>>aux2;
		switch(aux) {
		    case 0 : arr[aux1-1] = arr[aux2-1];
		    		 break;
		    case 1 : aux = 0;
		    		 for(int i = aux1 - 1; i <= aux2 - 1; i = i + 1){
		    			if(arr[i]%2==0) aux = aux + 1;
		    		 }
		    		 cout<<aux<<endl;
		    		 break;
		    default : aux = 0;
		    		  for(int i = aux1 - 1; i <= aux2 - 1; i = i + 1){
		    			 if(arr[i]%2!=0) aux = aux + 1;
		    		  }
		    		  cout<<aux<<endl;
		}
	}
	return 0;
}