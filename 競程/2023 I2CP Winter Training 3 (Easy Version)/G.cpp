#include<iostream>
using namespace std;
int D,I,T;

int main() {
	cin>>T;
	while(T--) {
		cin>>D>>I;
		I--;
		
		int x=1;
		for(int i=1;i<D;i++) {
			x*=2;
			if(I%2==1) x++;
			I/=2;
			
			//cout<<i<<' '<<x<<'\n';
		}
		
		cout<<x<<'\n';
	}
	
	return 0;
}
