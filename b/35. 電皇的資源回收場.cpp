#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
long long int N,V,sum=0;
gp_hash_table<int,long long int>mp;

int main() {
	//ios::sync_with_stdio(0);
 	//cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		int a;
		cin>>a;
		mp[a]++;
	}
	cin>>V;
	for(auto i:mp) {
		auto it=mp.find(V-i.first);
		if(i.first*2 < V && it != mp.end()) {
			sum += i.second*it->second;
		} else if(i.first*2 == V) {
			sum += (i.second)*(i.second-1)/2;
		}
	}
	cout<<sum;
	return 0;
} 
