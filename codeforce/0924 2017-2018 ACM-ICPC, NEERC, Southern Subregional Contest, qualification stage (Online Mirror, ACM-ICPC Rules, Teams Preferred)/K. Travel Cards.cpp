#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define mp make_pair
using namespace std;
int N,A,B,K,F;
map<pair<string,string>,int> m;
vector<int> vec;
int main() {
	cin>>N>>A>>B>>K>>F;
	
	string pre = "";
	for(int i=0;i<N;i++) {
		int cost = A;
		string from,to;
		cin>>from>>to;
		if(from == pre) cost = B;
		pre = to;
		if(from > to) swap(from,to);
		m[mp(from,to)] += cost;
	}
	
	long long int ans=0;
	for(auto i:m) {
		//cout<<i.second<<'\n';
		ans += i.second;
		vec.push_back(i.second);
	}
	sort(vec.rbegin(),vec.rend());
	for(int i=0;i<vec.size() && K>0;i++) {
		if(vec[i] > F) {
			ans -= (vec[i]-F);
			K--;
		} else {
			break;
		}
	}
	
	cout<<ans;
	
	return 0;
}
