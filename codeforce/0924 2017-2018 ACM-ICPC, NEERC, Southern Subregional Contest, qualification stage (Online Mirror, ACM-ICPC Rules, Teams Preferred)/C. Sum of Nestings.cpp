#include<iostream>
using namespace std;
long long int N,K;
string s="";
int main() {
	cin>>N>>K;
	int rank=0;
	if(N*(N-1)/2 < K) {
		cout<<"Impossible";
		return 0;
	}
	for(int i=0;i<2*N;i++) {
		if(rank <= K) {
			K -= rank;
			s += '(';
			rank++;
		} else {
			s += ')';
			rank--;
		}
	}
	cout<<s;
	
	return 0;
}
