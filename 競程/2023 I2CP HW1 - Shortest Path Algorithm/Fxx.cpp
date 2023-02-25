#include<iostream>
#include<vector>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int N,M,Q,dis[150];
vector<pii> road[150];

signed main() {
	while(cin>>N>>M>>Q) {
		if(N==0&&M==0&&Q==0) break;
		for(int i=0;i<N;i++) road[i].clear();
		
		for(int i=0;i<M;i++) {
			int u,v,w;
			cin>>u>>v>>w;
			road[u].emplace_back(v,w);
		}
		
		while(Q--) {
			int u,v;
			cin>>u>>v;
			for(int i=0;i<N;i++) dis[i]=1e18;
			dis[u]=0;
			
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					for(pii p:road[j]) dis[p.ff] = min(dis[p.ff],dis[j]+p.ss);
				}
			}
			int tmp=dis[v];
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					for(pii p:road[j]) dis[p.ff] = min(dis[p.ff],dis[j]+p.ss);
				}
			}
			
			if(dis[v]!=tmp) cout<<"-Infinity\n";
			else if(dis[v]==1e18) cout<<"Impossible\n";
			else cout<<dis[v]<<'\n';
		}
		cout<<'\n';
	}
	
	return 0;
} 
/*
2 2 2
0 1 -2
1 0 1
0 1
1 0*/
