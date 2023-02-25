#include<iostream>
#include<vector>
using namespace std;

struct Node {
	vector<int> back;
	bool circle=false;
	int vis_by=-1;
}node[100000];

int N,M,T;
vector<int> through;

void dfs(int from,int x) {
	//cout<<from<<" "<<x<<endl;
	if(from != x && node[x].vis_by!=-1) {
		int origin=node[x].vis_by;
		if(from!=origin && node[origin].vis_by==-1 && node[x].circle) {
			node[origin].vis_by=from;
		} else {
			return;
		}
	}
	
	if(from == x) {
		for(int i:through) {
			node[i].circle=true;
		}
		return;
	}else {
		node[x].vis_by=from;
	}
	
	for(int to:node[x].back) {
		if(T == to) continue;
		through.push_back(to);
		dfs(from,to);
		through.pop_back();
	}
	return;
}

int main() {
	//freopen("test08.in","r",stdin);
	cin>>N>>M>>T;
	for(int i=0;i<M;i++) {
		int from,to;
		cin>>from>>to;
		node[to].back.push_back(from);
	}
	
	for(int i:node[T].back) {
		for(int j:node[i].back) {
			if(j==T) continue;
			through.clear();
			dfs(i,j);
		}
	}
	
	vector<int> ans;
	for(int i:node[T].back) {
		if(node[i].vis_by==-1) ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(int i:ans) cout<<i<<endl;
	
	return 0;
}

