#include<iostream>
#include<queue>
#include<bitset>
#include<set>
#define F first
#define S second
#pragma GCC optimize("O3")
using namespace std;
struct Tree {
	int from;
	bitset<1001> have=0;
};

int N;
bitset<1001> vis;
set<pair<int,int>> ans;
queue<Tree> q;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		int K=N-1;
		while(K) {
			Tree t;
			t.from = i;
			int m;
			cin>>m;
			cin.ignore();
			K -= m;
			for(int j=0;j<m;j++) {
				int x;
				cin>>x;
				cin.ignore();
				t.have[x] = true;
			}
			q.push(t);
		}
	}
	
	bool no=false;
	while(!q.empty()) {
		int K=q.size();
		vis = 0;
		while(K--) {
			Tree t = q.front();
			q.pop();
			
			if(t.have.count() == 1) {
				int a=t.from,b=t.have._Find_first();
				if(ans.size() != N-1 && vis[a]) no=true;
				vis |= t.have;
				if(a > b) swap(a,b);
				ans.insert(pair<int,int> (a,b));
			} else q.push(t);
		}
		
		K = q.size();
		vis.flip();
		while(K--) {
			Tree t = q.front();
			q.pop();
			if(!vis[t.from]) continue;
			
			t.have &= vis;
			q.push(t);
		}
		vis.flip();
		if(vis==0) break;
	}
	
	if(ans.size() == N-1 && !no) {
		cout<<ans.size()<<'\n';
		for(auto i:ans) {
			cout<<i.first<<' '<<i.second<<'\n';
		}
	} else cout<<-1;
	
	/*while(q.size()) {
		Tree t = q.top();
		cout<<t.from<<'\n';
		for(int i:t.have) cout<<i<<' ';
		cout<<'\n'
		q.pop();
	}*/
	
	return 0;
}
