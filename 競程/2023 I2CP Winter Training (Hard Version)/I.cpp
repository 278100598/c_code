#include<iostream>
#include<vector>
using namespace std;
const int MX=1000000;
long long int ola[MX+1],ans[MX+1],T,N;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	for(int i=1;i<=MX;i++) ola[i]=i;
	for(int i=2;i<=MX;i++) {
		if(ola[i]!=i) continue;
		for(int j=i;j<=MX;j+=i) {
			ola[j] -= (ola[j]/i);
		}
	}
	
	for(int i=1;i<=MX;i++) {
		for(int j=i;j<=MX;j+=i) {
			ans[j] += ola[i]*i;
		}
	}
	
	for(int i=1;i<=MX;i++) {
		ans[i] = (ans[i]*i+i)/2;
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<ans[N]<<'\n';
	}
	
	return 0;
}
