#include<iostream>
#include<deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,x;
	cin>>n>>q;
	deque<int> l[n/100 + 1];
	for(int i=0;i<n;i++) {
		cin>>x;
		l[i/100].push_back(x);
	}
	for(int i=0;i<q;i++) {
		int a,total=0,it=0;
		cin>>x>>a;
		while(total+l[it].size()<a) {
			total+=l[it].size();
			it++;
		}
		if(x==1) {
			cin>>x;
			l[it].insert(l[it].begin()+(a-total)-1,x);
		}
		else if(x==2) {
			l[it].erase(l[it].begin()+(a-total)-1);
		}
		
	}
	for(int i=0;i<n/100 + 1;i++) {
		for(auto it=l[i].begin();it!=l[i].end();it++) {
			cout<<*it<<" ";
		}
	}
	return 0;
} 
