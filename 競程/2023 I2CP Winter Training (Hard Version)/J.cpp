#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
const int MX=100000;
struct Node {
	int l,r,cnt=0;
}nodes[MX*33];
vector<int> road[MX+1];
int N,M,root[MX+1],ori[MX+1],p[MX+1][32],d[MX+1],now=0;
pii all[MX+1];
bool vis[MX+1];
map<int,int> pos;

int init(int l=1,int r=N) {
	int i=now++;
	if(l==r) return i;
	int m=(l+r)/2;
	nodes[i].l=init(l,m);
	nodes[i].r=init(m+1,r);
	return i;
}

int build(int x,int rt,int l=1,int r=N) {
	int i=now++;
	nodes[i]=nodes[rt];
	nodes[i].cnt++;
	//cout<<x<<' '<<nodes[i].cnt<<' '<<l<<' '<<r<<'\n';
	if(l==r) return i;
	int m=(l+r)/2;
	if(x<=m) {
		nodes[i].l=build(x,nodes[rt].l,l,m);
	} else {
		nodes[i].r=build(x,nodes[rt].r,m+1,r);
	}
	return i;
}

void dfs(int pre,int x) {
	vis[x]=true;
	p[x][0]=pre;
	d[x]=d[pre]+1;
	for(int i=1;i<32;i++) {
		if(p[p[x][i-1]][i-1]) p[x][i]=p[p[x][i-1]][i-1];
		else break;
	}
	root[x]=build(pos[ori[x]],root[pre]);
	
	for(int i:road[x]) {
		if(!vis[i]) dfs(x,i);
	}
}

int lca(int u,int v) {
	if(d[u]<d[v]) swap(u,v);
	for(int i=31;i>=0;i--) {
		//cout<<i<<' '<<u<<' '<<v<<'\n';
		if((d[u]-d[v])&(1<<i)) u=p[u][i];
	}
	//cout<<u<<' '<<v<<'\n';
	if(u==v) return u;
	for(int i=31;i>=0;i--) {
		if(p[u][i]!=p[v][i]) {
			u=p[u][i];
			v=p[v][i];
		}
	}
	return p[u][0];
}

int find(int u,int v,int a,int pa,int k,int l=1,int r=N) {
	if(l==r) return l;
	int x=nodes[nodes[u].l].cnt+nodes[nodes[v].l].cnt-nodes[nodes[a].l].cnt-nodes[nodes[pa].l].cnt;
	/*cout<<l<<' '<<r<<' '<<k<<'\n'; 
	cout<<"u "<<u<<' '<<nodes[u].cnt<<'\n';
	cout<<"v "<<v<<' '<<nodes[v].cnt<<'\n';
	cout<<"a "<<a<<' '<<nodes[a].cnt<<'\n';
	cout<<"pa "<<pa<<' '<<nodes[pa].cnt<<'\n';*/
	int m=(l+r)/2;
	if(k<=x) return find(nodes[u].l,nodes[v].l,nodes[a].l,nodes[pa].l,k,l,m);
	else return find(nodes[u].r,nodes[v].r,nodes[a].r,nodes[pa].r,k-x,m+1,r);
}

int main() {
	cin>>N>>M;
	pos.clear();
	for(int i=0;i<=N;i++) {
		road[i].clear();
		vis[i]=false;
		for(int j=0;j<32;j++) p[i][j]=0;
	}
	
	for(int i=1;i<=N;i++) {
		cin>>ori[i];
		all[i]=pii(ori[i],i);
	}
	sort(all+1,all+N+1);
	for(int i=1;i<=N;i++) pos[all[i].ff]=i;
	
	for(int i=1;i<N;i++) {
		int u,v;
		cin>>u>>v;
		road[u].push_back(v);
		road[v].push_back(u);
	}
	
	root[0] = init();
	dfs(0,1);
	
	for(int i=0;i<M;i++) {
		int u,v,k;
		cin>>u>>v>>k;
		int a=lca(u,v);
		int ret=find(root[u],root[v],root[a],root[p[a][0]],k);
		cout<<all[ret].ff<<'\n';
	}
	
	return 0;
}
