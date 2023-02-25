#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int ab=-1;
	vector<int> to;
	bool vis=false;
}node[300001];
int N,M;

void dfs(int x) {
	if(node[x].vis) return;
	
	node[x].ab=1;
	node[x].vis=true;
	for(int to:node[x].to) dfs(to);
}

int main() {
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		int a,b;
		cin>>a>>b;
		node[a].to.push_back(b);
		node[b].to.push_back(a);
	}
	
	node[N].ab=0;
	node[N].vis=true;
	dfs(N-1);
	
	for(int i=1;i<=N;i++) {
		if(node[i].ab==0 || node[i].ab==-1) cout<<"A";
		else if(node[i].ab==1) cout<<"B";
	}
	return 0;
}
