#include<iostream>
using namespace std;
long long int N,get[1001],mul[1001],coin[1001][1001],x,d[1001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	for(int i=0;i<=N;i++) d[i]=-1;
	for(int i=1;i<=N;i++) cin>>get[i];
	for(int i=1;i<=N;i++) cin>>mul[i];
	
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>x;
			if(j<=i) continue;
			if(x <= get[i]) coin[i][j] = (get[i]-x)*mul[i];
			else coin[i][j]=-1;
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>x;
			if(j<=i) continue;
			if(coin[i][j] != -1) {
				coin[i][j] += x;
			}
		}
	}
	
	d[1]=0;
	for(int i=1;i<=N;i++) {
		if(d[i]==-1)continue;
		for(int j=i+1;j<=N;j++) {
			if(coin[i][j]!=-1) d[j] = max(d[j],d[i]+coin[i][j]);
		}
	}
	cout<<d[N];
	return 0;
}

