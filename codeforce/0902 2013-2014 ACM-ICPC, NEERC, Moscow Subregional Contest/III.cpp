#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int N;
set<int> st[201],inter[201][201];

int main() {
	cin>>N;
	int M=N*(N-1)/2;
	for(int i=0;i<M;i++) {
		int a,b,K,x;
		cin>>a>>b>>K;
		if(a > b) swap(a,b);
		for(int j=0;j<K;j++) {
			cin>>x;
			st[a].insert(x);
			st[b].insert(x);
			inter[a][b].insert(x);
		}
	}
	
	bool y=true;
	for(int i=1;i<=N;i++) {
		for(int j=i+1;j<=N;j++) {
			if(!y) continue;
			
			set<int> s;
			set_intersection(st[i].begin(),st[i].end(),st[j].begin(),st[j].end(),inserter(s,s.begin()));
			if(s.size() != inter[i][j].size()) {
				y=false;
				break;
			}
			
			for(auto a=s.begin(),b=inter[i][j].begin();a!=s.end();a++,b++) {
				if(*a != *b) y=false;
			}
		}
	}
	
	if(y) {
		cout<<"Yes"<<endl;
		for(int i=1;i<=N;i++) {
			cout<<st[i].size();
			for(int it:st[i]) cout<<" "<<it;
			cout<<endl;
		}
	} else cout<<"No";
	return 0;
}
