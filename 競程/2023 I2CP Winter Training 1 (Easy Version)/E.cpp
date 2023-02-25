#include<iostream>
#include<map>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int arr[1000001],N,Q;
map<int,int> m;


int main() {
	cin>>N>>Q;
	for(int i=1;i<=N;i++) cin>>arr[i];
	int now=1;
	for(int i=1;i<N;i++) {
		if(arr[i+1]%arr[i] != 0) {
			m[i]=now;
			now=i+1;
		}
	}
	m[N]=now;
	
	
	while(Q--) {
		int q;
		cin>>q;
		if(q==1) {
			int i,x;
			cin>>i>>x;
			arr[i]=x;
			auto it = m.lower_bound(i);
			int l=it->ss,r=it->ff;
			m.erase(it);
			
			if(i==l) {
				if(i!=1 && arr[i]%arr[i-1]==0) {
					it = m.lower_bound(l-1);
					l=it->ss;
					m.erase(it);
				}
			} else {
				if(arr[i]%arr[i-1]!=0) {
					m[i-1]=l;
					l=i;
				}
			}
			
			if(i==r) {
				if(i!=N && arr[i+1]%arr[i]==0) {
					it = m.lower_bound(r+1);
					r=it->ff;
					m.erase(it);
				}
			} else {
				if(arr[i+1]%arr[i]!=0) {
					m[r]=i+1;
					r=i;
				}
			}
			
			m[r]=l;
		} else if(q==2) {
			int i;
			cin>>i;
			auto it = m.lower_bound(i);
			cout<<it->ss<<'\n';
		}
	}
	
	return 0;
}
