#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair 
#define F first
#define S second
using namespace std;
int T,N,arr[200001];
map<int,int> l,r,cnt;

int main() {
	cin>>T;
	while(T--) {
		cin>>N;
		l.clear();
		r.clear();
		cnt.clear();
		for(int i=0;i<N;i++) {
			int x;
			cin>>x;
			arr[i]=x;
			l[x]++;
		}
		for(int i=0;i<N;i++) {
			int x;
			cin>>x;
			if(x == arr[i]) cnt[x]++;
			r[x]++;
		}
		
		vector<int> k; 
		auto i=l.begin(),j=r.begin();
		while(i!=l.end() && j !=r.end()) {
			while(i->F < j->F) {
				k.push_back(i->F);
				i++;
			}
			while(i->F > j->F) {
				k.push_back(i->F);
				j++;
				continue;
			}
			
			if(i->S - j->S != 0) k.push_back(i->F);
			else if(cnt.find(i->F) != cnt.end()) {
				if(i->S - cnt[i->F] == 0) k.push_back(i->F);
			}
			if(k.size() > 2) break;
		}
		
		if(k.size() > 2) cout<<"-1\n";
		else if(k.size() == 2){
			
		} else if(k.size() == 1) {
			
		} else {
		}
		
		
	}
	
	return 0;
}
