#include<iostream>
using namespace std;
int main() {
	long long int W,N,s=0;
	cin>>W>>N;
	for(int i=0;i<N;i++) {
		int a,b;
		cin>>a>>b;
		s+=(a*b);
	}
	cout<<(s/W);
	return 0;
}
