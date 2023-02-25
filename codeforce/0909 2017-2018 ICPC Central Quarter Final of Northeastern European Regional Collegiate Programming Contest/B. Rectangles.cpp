#include<iostream>
#include<set>
#include<Math.h>
#define ll long long int
#define mp make_pair
using namespace std;
ll N;
set<ll> a,b;
set<pair<ll,ll>> ans;
int main() {
	cin>>N;
	for(int i=1;i<=sqrt(N+1);i++) {
		if((N+1)%i == 0) {
			a.insert(i);
			a.insert((N+1)/i);
		}
	}
	for(int i=1;i<=sqrt(N);i++) {
		if(N%i == 0) {
			b.insert(i);
			b.insert(N/i);
		}
	}
	
	for(ll i:a) {
		for(ll j:b) {
			if(i*j <= 4*N*(N+1)/(i*j)) ans.insert(pair<ll,ll>(i*j + 2*(N+1),(4*N*(N+1)/(i*j) + 2*(N+1))));
			else break;
			if(i*j*2 <= 2*N*(N+1)/(i*j)) ans.insert(pair<ll,ll>(i*j*2 + 2*(N+1),(2*N*(N+1)/(i*j) + 2*(N+1))));
			if(i*j*4 <= N*(N+1)/(i*j)) ans.insert(pair<ll,ll>(i*j*4 + 2*(N+1),(N*(N+1)/(i*j) + 2*(N+1))));
		}
	}
	
	cout<<ans.size()<<'\n';
	for(auto i:ans) cout<<i.first<<" "<<i.second<<'\n';
	
	return 0;
}
