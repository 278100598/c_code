#include<iostream>
using namespace std;
int N,f[250],dp[250][250],pre[251];

int go(int l,int r) {
	if(dp[l][r] != -1) return dp[l][r];
	else if(l==r) return f[l];
	else if(r<l) return 0;
	
	int mn=go(l+1,r);
	for(int i=l+1;i<r;i++) mn = min(mn,go(l,i-1)+go(i+1,r));
	mn = min(mn,go(l,r-1));
	
	dp[l][r]= pre[r+1]-pre[l]+mn;
	return dp[l][r];
}

int main() {
	while(cin>>N) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) dp[i][j]=-1;
		}
		pre[0]=0;
		for(int i=0;i<N;i++) {
			cin>>f[i];
			pre[i+1] = pre[i]+f[i];
		}
		
		cout<<go(0,N-1)-pre[N]<<'\n';
	}
	
	return 0;
}
