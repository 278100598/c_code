#include<iostream>
#include<vector>
#include<queue>
#define mp make_pair
#define ff first
#define ss second
using namespace std;
int T,N,M,A;
struct Edge {
	int u,v,w;
	Edge(int a,int b,int c) {u=a,v=b,w=c;};
};

vector<Edge> edges;
vector<int> road[10001];
struct cmp{
	bool operator() (int a,int b) {
		if(edges[a].w == edges[b].w) {
			return !(edges[a].u==0||edges[a].v==0);
		}
		return edges[a].w > edges[b].w;
	}
};

int main() {
	cin>>T;
	for(int turn=1;turn<=T;turn++) {
		cin>>N>>M>>A;
		for(int i=0;i<=N;i++) road[i].clear();
		for(int i=1;i<=N;i++) {
			road[0].push_back(edges.size());
			road[i].push_back(edges.size());
			edges.emplace_back(0,i,A);
		}
		
		for(int i=0;i<M;i++) {
			int x,y,c;
			cin>>x>>y>>c;
			road[x].push_back(edges.size());
			road[y].push_back(edges.size());
			edges.emplace_back(x,y,c);
		}
		
		priority_queue<int,vector<int>,cmp> pq;
		bool vis[edges.size()],vvis[N+1];
		for(int i=0;i<edges.size();i++) vis[i]=false;
		for(int i=0;i<=N;i++) vvis[i]=false;
		for(int i:road[0]) {
			pq.push(i);
			vis[i]=true;
		}
		vvis[0]=true;
		
		long long int sum=0,cnt=0;
		while(!pq.empty()) {
			Edge e=edges[pq.top()];
			pq.pop();
			if(vvis[e.u] && vvis[e.v]) continue;
			else if(vvis[e.u]) swap(e.u,e.v);
			vvis[e.u]=true;
			
			sum += e.w;
			if(e.u==0||e.v==0) cnt++;
			for(int i:road[e.u]) {
				if(!vis[i]) {
					vis[i]=true;
					pq.push(i);
				}
			}
		}
		
		cout<<"Case #"<<turn<<": "<<sum<<' '<<cnt<<'\n';
	}
	
	return 0;
}
