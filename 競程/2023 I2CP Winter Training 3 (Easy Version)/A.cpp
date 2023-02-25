#include<iostream>
#include<map>
#include<vector>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
map<pii,int> m;
vector<pii> v;

int main() {
	int x,y;
	while(cin>>x>>y) {
		m.clear();
		if(x<y) swap(x,y);
		m[pii(x,y)]++;
		for(int i=0;i<5;i++) {
			cin>>x>>y;
			if(x<y) swap(x,y);
			m[pii(x,y)]++;
		}
		v.clear();
		for(auto it:m) {
			while(it.ss>=2) {
				it.ss-=2;
				v.push_back(it.ff);
			}
		}
		
		bool y=false;
		if(v.size()==3) {
			if(v[0].ff==v[1].ff) {
				if((v[1].ss==v[2].ff&&v[2].ss==v[0].ss) || (v[1].ss==v[2].ss&&v[2].ff==v[0].ss)) {
					y=true;
				}
			}
			if(v[0].ff==v[1].ss) {
				if((v[1].ff==v[2].ff&&v[2].ss==v[0].ss) || (v[1].ff==v[2].ss&&v[2].ff==v[0].ss)) {
					y=true;
				}
			}
			if(v[0].ff==v[2].ff) {
				if((v[2].ss==v[1].ff&&v[1].ss==v[0].ss) || (v[2].ss==v[1].ss&&v[1].ff==v[0].ss)) {
					y=true;
				}
			}
			if(v[0].ff==v[2].ss) {
				if((v[2].ff==v[1].ff&&v[1].ss==v[0].ss) || (v[2].ff==v[1].ss&&v[1].ff==v[0].ss)) {
					y=true;
				}
			}
		}
		if(y) cout<<"POSSIBLE\n";
		else cout<<"IMPOSSIBLE\n";
	}
	
	return 0;
}
