#include <bits/stdc++.h>
#define int long long
using namespace std;
int lcm(int a, int b){
	int c = __gcd(a, b);
	return (a/c)*(b/c)*c;
}
const int N = 3e5+25, MX = 1e6+25;
int cnt[MX], arr[N];
bitset <MX> used;
vector <int> sorted_cnt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("equal.in", "r", stdin);
	//freopen("equal.out", "w", stdout);
	int n, x, L=1;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
		L = lcm(L, arr[i]);
		if (L > 1000000){
			L = 1e9+7;
		}
	}
	for (int i = 0; i < n; i++){
		if (used[arr[i]]) continue;
		used[arr[i]] = 1;
		sorted_cnt.emplace_back(cnt[arr[i]]);
	}
	int now = sorted_cnt.size(), check=0;
	sort(sorted_cnt.begin(), sorted_cnt.end());
	cout << now << " ";
	for (int i = 0; i < sorted_cnt.size(); i++){
		while (--sorted_cnt[i]){
			cout << now << " ";
		}
		if ((L == 1e9+7 or !used[L]) && check==0) now++, check=1;
		cout << --now << " ";
	}
}
