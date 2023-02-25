#include<iostream>
#include<vector>
#define int long long
using namespace std;
int N,M,Q,d[150][150];
vector<int> road[150];

signed main() {
	while(cin>>N>>M>>Q) {
		if(N==0&&M==0&&Q==0) break;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) d[i][j]=1e18;
			d[i][i]=0;
		}
		
		for(int i=0;i<M;i++) {
			int u,v,w;
			cin>>u>>v>>w;
			d[u][v]=min(d[u][v],w);
			road[v].push_back(u);
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(d[j][i]==1e18) continue;
				for(int k=0;k<N;k++) {
					if(d[i][k]!=1e18) {
						d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
					}
				} 
			}
		}
		
		while(Q--) {
			int u,v;
			cin>>u>>v;
			if(d[u][v]==1e18) {
				cout<<"Impossible\n";
				continue;
			}
			
			
			bool flag=false;
			for(int i=0;i<N;i++) {
				if(d[u][i]!=1e18 && d[i][v]!=1e18 && d[i][i]<0) flag=true;
			}
			if(flag) cout<<"-Infinity\n";
			else cout<<d[u][v]<<'\n';
		}
		cout<<'\n';
	}
	
	return 0;
} 
