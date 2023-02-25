#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
long long int N,M,A,B;
vector<pair<int,int>> road[200001];
int vis[200001];
priority_queue<pair<long long int,int>> pq;



int main() {
	cin>>N>>M>>A>>B;
	for(int i=1;i<=N;i++) {
		vis[i]=-1;
	}
	for(int i=1;i<=M;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		road[u].emplace_back(v,w);
		road[v].emplace_back(u,w);
	}
	
	pq.push(mp(0,1))
	while(!pq.empty()) {
		
		
	}
	
	
	
	return 0;
}
