#include<iostream>
#include<vector>
using namespace std;
int N,x;
vector<vector<int>> vec;
int main() {
	cin>>N>>x;
	vec.push_back({x});
	for(int i=1;i<N;i++) {
		cin>>x;
		int l=0,r=vec.size();
		while(l != r) {
			int m=(l+r)/2;
			
			if(vec[m].back() < x) r = m;
			else l = m+1;
		}
		if(r == vec.size()) vec.push_back({x});
		else vec[r].push_back(x);
	}
	
	for(auto i:vec) {
		for(int j:i) cout<<j<<' ';
		cout<<'\n';
	}
	
	
	return 0;
}
