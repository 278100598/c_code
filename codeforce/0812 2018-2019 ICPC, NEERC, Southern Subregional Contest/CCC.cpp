#include <bits/stdc++.h>
#define F first
#define S second
#define MP(x, y) make_pair(x, y)
#define mid (l+r)/2
#define lson (root<<1)+1
#define rson (root<<1)+2
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 1e6+5;
vector <pair<int, pair<pair<int, int>, int> > > arr; //1 2 5 10
int ary[N];
int tag[(N<<3)];
long long now, n, ans, cnt=0;
long long tree[(N<<2)];
void build(int l, int r, int root){
	if (l==r){
	   tree[root] = ary[l];
	   return;
	}
	build(l, mid, lson);
	build(mid+1, r, rson);
	tree[root] = tree[lson]+tree[rson];
}
/*
void modify(int root){
	if (root >= n4) return;
	tree[root] = 0;
	modify(lson);
	modify(rson);
}*/
void add(int a, int b, int p, int l, int r, int root){
	cnt++;
	if (tag[root] == 999){
		tag[lson] = 999, tag[rson] = 999;
		tree[root] = 0;
		return;
	}
	if (r<a || l>b) return;
	if (l>=a && r<=b){
		if (l==r){
			if (tree[root] == 0) return;
			else{
				if (tree[root] <= now){
					ans += tree[root]*p;
					tree[root] = 0;
				}else{
					ans += now*p;
					tree[root] -= now;
				}
			}
			return;
		}
		if (tree[root] == 0) return;
		if (tree[root] <= now){
			ans += p*tree[root];
			tree[root] = 0;
			tag[lson] = 999;
			tag[rson] = 999;
//			modify(root);
		}else{
			add(a, b, p, l, mid, lson);
			add(a, b, p, mid+1, r, rson);
			tree[root] = tree[lson] + tree[rson];
		}
		return;
	}else{
		add(a, b, p, l, mid, lson);
		add(a, b, p, mid+1, r, rson);
		tree[root] = tree[lson] + tree[rson];
		return;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) ary[i] = k;
	build(0, n-1, 0);
	int l, r, c, p;
	for (int i = 0; i < m; i++){
		cin >> l >> r >> c >> p;
		l--, r--;
		arr.emplace_back(p, MP(MP(l, r), c));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < m; i++){
		now = arr[i].S.S;
		add(arr[i].S.F.F, arr[i].S.F.S, arr[i].F, 0, n-1, 0);
	}
	cout << ans << " " << cnt <<"\n";
}
