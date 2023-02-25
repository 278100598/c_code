#include<iostream>
#include<map>
#include<vector>
#define cost first
#define gain second
using namespace std;
struct Food {
	string a,b;
	int cost,gain;
};
map<string,vector<Food>>before;
map<string,pair<int,int> >after;
int d[10001];

void go(string s) {
	string a,b;
	int c=-1,g=-1;
	for(auto f:before[s]) {
		int cc=f.cost,gg=f.gain;
		if(before.find(f.a) != before.end()) {
			if(after.find(f.a) == after.end()) go(f.a);
			cc+=after[f.a].cost;
			gg+=after[f.a].gain;
		}
		if(after.find(f.b) != after.end()) {
			if(after.find(f.b) == after.end()) go(f.b);
			cc+=after[f.b].cost;
			gg+=after[f.b].gain;
		}
		//cout<<s<<" "<<before[s].size()<<" "<<cc<<" "<<gg<<endl;
		if(cc<c || (cc==c&&gg>g) || c==-1) {
			c=cc;
			g=gg;
		}
	}
	after[s].cost = c;
	after[s].gain = g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int B,N;
	cin>>B>>N;
	for(int i=0;i<N;i++) {
		string name;
		cin>>name;
		Food f;
		cin>>f.a>>f.b>>f.cost>>f.gain;
		before[name].push_back(f);
	}
	
	for(auto it=before.begin();it!=before.end();it++) {
		if(after.find(it->first) == after.end()) {
			go(it->first);
		}
		auto i = after[it->first];
		//cout<<it->first<<" "<<i.cost<<" "<<i.gain<<endl;
	}
	
	for(int i=1;i<=B;i++) d[i]=-1;
	d[0]=0;
	for(auto it:after) {
		int c=it.second.cost,g=it.second.gain;
		for(int i=B-1;i>=0;i--) {
			if(d[i]!=-1 && i+c<=B) {
				d[i+c]=max(d[i+c],d[i]+g);
			}
		}
	}
	
	int mx=-1,cost;
	for(int i=0;i<=B;i++) {
		if(d[i]>mx) {
			mx=d[i];
			cost=i;
		}
	}
	
	cout<<mx<<endl<<cost;
	return 0;
} 
