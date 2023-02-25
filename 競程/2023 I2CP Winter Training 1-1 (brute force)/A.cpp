#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int T,N;
vector<pii> cnt;
vector<int> tmp;
vector<vector<int>> ans; 

void go(int x,int sum) {
	if(x==cnt.size() && sum==T) {
		ans.push_back(tmp);
		sort(ans.back().rbegin(),ans.back().rend());
		return;
	} else if(sum>T || x==cnt.size()) return;
	
	go(x+1,sum);
	for(int i=0;i<cnt[x].ss;i++) {
		tmp.push_back(cnt[x].ff);
		sum+=cnt[x].ff;
		go(x+1,sum);
	}
	for(int i=0;i<cnt[x].ss;i++) tmp.pop_back();
	
}

int main() {
	while(cin>>T>>N) {
		if(N==0) break;
		
		map<int,int> m;
		for(int i=0;i<N;i++) {
			int x;
			cin>>x;
			m[x]++;
		}
		
		cnt.clear();
		for(auto it:m) cnt.push_back(it);
		ans.clear();
		go(0,0);
		sort(ans.rbegin(),ans.rend());
		
		printf("Sums of %d:\n",T);
		if(ans.empty()) cout<<"NONE\n";
		else {
			for(auto v:ans) {
				cout<<v[0];
				for(int i=1;i<v.size();i++) cout<<'+'<<v[i];
				cout<<'\n';
			}
		}	
	}
	
	return 0;
}
