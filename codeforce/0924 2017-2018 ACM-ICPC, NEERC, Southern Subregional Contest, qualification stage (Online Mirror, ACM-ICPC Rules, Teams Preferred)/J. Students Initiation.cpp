#include<iostream>
#include<vector>
using namespace std;
int N,M,now=0;
bool vis[5001];
vector<int> give[5001];
bool dfs(int giver,int reciver) {
	if(vis[giver]) return false;
	vis[giver] = true;
	if(give[giver].size() < now) {
		give[giver].push_back(reciver);
		return true;
	}
	
	for(int i=0;i<give[giver].size();i++) {
		if(dfs(give[giver][i],giver)) {
			give[giver][i] = reciver;
			return true;
		}
	}
	return false;
}

bool go(int a,int b) {
	for(int i=1;i<=N;i++) vis[i]=false;
	return dfs(a,b);
}

int main() {
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		int a,b;
		cin>>a>>b;
		if(go(a,b)) continue;
		if(go(b,a)) continue;
		
		now++;
		go(a,b);
	}
	
	cout<<now<<'\n';
	for(int i=1;i<=N;i++) {
		for(int j:give[i]) cout<<i<<' '<<j<<'\n';
	}
	
	return 0;
}
