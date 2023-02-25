#include<bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;

int N,M;
long long int dp[1001][1001];

int main() {
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) dp[i][j]=-INF;
		dp[i][i]=0;
	}
	for(int i=0;i<M;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		dp[a][b]=c;
	}
	
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			for(int k=1;k<=N;k++) {
				if(dp[j][i]!=-INF && dp[i][k]!=-INF) {
					dp[j][k] = max(dp[j][k],dp[j][i]+dp[i][k]);
				}
			} 
		}
	}
	
	for(int i=1;i<=N;i++) {
		if(dp[1][i]!=-INF && dp[i][N]!=-INF && dp[i][i]!=0) {
			cout<<"inf";
			return 0;
		}
	}
	
	cout<<dp[1][N];
	
	return 0;
}
