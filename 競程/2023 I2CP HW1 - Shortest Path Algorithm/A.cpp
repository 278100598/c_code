#include<bits/stdc++.h>
#define pii pair<long long int,int>
#define ff first
#define ss second
using namespace std;
struct Edge {
	long long int T,K,to;
	Edge(int x,long long int k,long long int t) {
		to = x;
		K=k;
		T=t;
	}
};

vector<Edge> E;
vector<int> road[100001];
long long int X,Y,N,M,dis[100001];

int main() {
	cin>>N>>M>>X>>Y;
	for(int i=0;i<M;i++) {
		int a,b,t,k;
		cin>>a>>b>>t>>k;
		road[a].push_back(E.size());
		E.emplace_back(b,k,t);
		road[b].push_back(E.size());
		E.emplace_back(a,k,t);
	}
	
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.emplace(0,X);
	for(int i=1;i<=N;i++) dis[i]=1e18;
	dis[X]=0;
	while(!pq.empty()) {
		int len=pq.top().ff,x=pq.top().ss;
		pq.pop();
		if(dis[x] < len) continue;
		//cout<<len<<' '<<x<<'\n';
		if(x==Y) break;
		
		for(int i:road[x]) {
			Edge &e = E[i];
			long long int t=dis[x];
			if(t%e.K!=0) t+= e.K-(t%e.K);
			
			if(t+e.T < dis[e.to]) {
				dis[e.to] = t+e.T;
				pq.emplace(dis[e.to],e.to);
			}
		}
	}
	
	if(dis[Y]==1e18) cout<<-1;
	else cout<<dis[Y];
	
	return 0;
}
