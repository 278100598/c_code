#include<iostream>
using namespace std;
int T,N,ans[100001];

int main() {
	for(int i=1;i<=100000;i++) ans[i]=1e9;
	for(int i=1;i<=100000;i++) {
		int x=i,sum=i;
		while(x!=0) {
			sum += x%10;
			x /= 10;
		}
		if(sum <= 100000 && ans[sum]==1e9) ans[sum]=i;
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		if(ans[N] == 1e9) cout<<0<<'\n';
		else cout<<ans[N]<<'\n';
	}
	
	return 0;
}
