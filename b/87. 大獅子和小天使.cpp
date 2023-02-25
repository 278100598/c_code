#include<iostream>
#include<vector>
using namespace std;
struct Node {
	bool vis=false;
	int val,level,from;
	vector<int> go;
}node[100001];
int N,Q;

void build(int from,int now,int level) {
	if(node[now].vis) return;
	node[now].vis=true;
	node[now].from=from;
	node[now].level=level;
	for(int i:node[now].go) {
		if(i==from) continue;
		build(now,i,level+1);
	}
}

int find(int a,int b) {
	int mx=-1;
	while(node[a].level > node[b].level) {
		a=node[a].from;
		mx=max(mx,node[a].val);
	}
	while(node[a].level < node[b].level) {
		b=node[b].from;
		mx=max(mx,node[b].val);
	}
	while(a!=b) {
		a=node[a].from;
		b=node[b].from;
		mx=max(mx,max(node[a].val,node[b].val));
	}
	return max(mx,node[a].val);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>N>>Q;
	//if(N!=30) return 0;
	for(int i=1;i<=N;i++) {
		cin>>node[i].val;
	}
	for(int i=1;i<N;i++) {
		int a,b;
		cin>>a>>b;
		node[a].go.push_back(b);
		node[b].go.push_back(a);
	}
	build(0,1,0);
	
	
	for(int i=0;i<Q;i++) {
		int a,b;
		cin>>a>>b;
		cout<<node[a].val<<" "<<node[b].val<<endl;
		cout<<find(a,b)<<'\n';
	}
	
	return 0;
}
/*
15 29
15 938
29 773

16 10
1 28
10 30

*/
