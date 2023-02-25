#include<bits/stdc++.h>
using namespace std;
int N,M,len[100001];
int main() {
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>len[i];
	
	int mx=0;
	for(int i=0;i<M;i++) {
		int t,f;
		cin>>t>>f;
		mx = max(mx,t+len[f]);
	}
	
	cout<<mx;
	
	return 0;
}
