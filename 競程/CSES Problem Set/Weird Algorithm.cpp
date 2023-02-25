#include<iostream>
using namespace std;

int main() {
	long long int N;
	cin>>N;
	while(N!=1) {
		cout<<N<<' ';
		if(N%2==0) N/=2;
		else N=N*3+1;
	}
	cout<<1;
	
	return 0;
}
