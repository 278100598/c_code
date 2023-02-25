#include <bits/stdc++.h> 
#pragma GCC optimize("O2")
using namespace std;
 
vector<int> v, fac;
set <int> ans; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n, i;
    cin>>n;

	int sn = sqrt(n), n2 = (n>>1);
    for(i = 1; i <= sn;i++){
		if (n%i == 0){
			if (n/i%2 == 0){
				ans.insert(i);
			}
			if ((i)%2 == 0) ans.insert(n/i);
		}
    }
    cout << ans.size() << "\n";
	for (auto i : ans) cout << i << " ";
    cout << "\n";
    return 0;
}
