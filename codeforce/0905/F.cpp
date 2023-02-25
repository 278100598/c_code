#include <bits/stdc++.h>
#define int long long
#define MXN 200005
//#define SZ(x) x.size()
using namespace std;
vector <pair<int, int> > ouo[MXN];
int keep[MXN];
bitset<MXN> vis;
int ans;
int dfs(int now, int load){
	vis[now] = true;
	int have = min(keep[now],load);
	ans += have;
	load -= keep[now];
	
	for (auto i : ouo[now]){
		if (vis[i.first]) continue;
		
		if(load > 0) {
			int get = dfs(i.first, min(i.second,load));
			load -= get;
			have += get;
		}
	}
	//cout<<now<<" "<<load<<" "<<have<<endl;
	return have;
}
signed main() {
	ios::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, ci, u, v, w;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			ouo[i].clear();
			vis[i] = false;
		}
			
		for (int i = 1; i <= n; i++ ){
			cin >> keep[i];
		}
		ans = 0;
		for (int i = 0; i < n-1; i++){
			cin >> u >> v >> w;
			ouo[u].emplace_back(v, w);
			ouo[v].emplace_back(u, w);
		}
		dfs(1, 1e18+7);
		cout<<ans<< "\n";
	}
} 
/*
1 
6
1 1 1 1 1 1
1 2 6 
2 3 1 
2 4 3
4 5 1
4 6 1
*/ 
