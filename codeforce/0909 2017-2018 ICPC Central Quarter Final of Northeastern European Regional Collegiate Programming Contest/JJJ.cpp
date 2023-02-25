#include<iostream>
#include<iomanip>
#include<cMath>
using namespace std;
long long int N,M,x[100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) cin>>x[i];
	x[0]=0;
	for(int i=1;i<=N;i++) {
		int a;
		cin>>a;
		x[i] = x[i-1] + (x[i]-a)*(x[i]-a);
	}
	
	cin>>M;
	for(int i=0;i<M;i++) {
		int l,r;
		cin>>l>>r;
		cout<<fixed<<setprecision(6)<<sqrt(x[r]-x[l-1])<<'\n';
	}
	
	return 0;
} 
