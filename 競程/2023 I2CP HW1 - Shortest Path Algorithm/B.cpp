#include<bits/stdc++.h>
#define pii pair<long long int,int>
#define ff first
#define ss second
using namespace std;
struct Edge {
	long long int C,to,idx;
	Edge(int x,long long int c,int i) {
		to = x;
		C = c;
		idx = i;
	}
};

vector<Edge> E;
vector<int> road[200001];
long long int X,Y,N,M,dis[200001],from[200001];

int main() {
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		road[a].push_back(E.size());
		E.emplace_back(b,c,i);
		road[b].push_back(E.size());
		E.emplace_back(a,c,i);
	}
	
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for(int i=1;i<=N;i++) dis[i]=1e18;
	pq.emplace(0,1);
	dis[1]=0;
	while(!pq.empty()) {
		int len=pq.top().ff,x=pq.top().ss;
		pq.pop();
		if(dis[x] < len) continue;
		//cout<<len<<' '<<x<<'\n';
		if(x==Y) break;
		
		for(int i:road[x]) {
			Edge &e = E[i];
			
			if(dis[x]+e.C < dis[e.to]) {
				dis[e.to] = dis[x]+e.C;
				from[e.to] = e.idx;
				pq.emplace(dis[e.to],e.to);
			}
		}
	}
	
	for(int i=2;i<=N;i++) cout<<from[i]<<' ';
	
	return 0;
}
