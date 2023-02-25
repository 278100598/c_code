#include<iostream>
#include<map>
using namespace std;
string con[10000],s;
int v[10000],N,M;
map<string,int> m,conv;

int main() {
	cin>>N>>M;
	
	for(int i=0;i<N;i++) {
		cin>>s;
		m[s]=i;
		cin>>s;
		con[i]=s;
	}
	
	for(int i=0;i<M;i++) {
		cin>>s;
		conv[con[m[s]]]++;
		v[m[s]]++;
	}
	
	string ans;
	int mx=-1e9;
	for(auto it:conv) {
		if(mx < it.second) {
			mx = it.second;
			ans = it.first;
		}
	}
	cout<<ans<<'\n';
	
	mx = -1e9;
	for(auto it:m) {
		if(mx < v[it.second]) {
			mx = v[it.second];
			ans = it.first;
		}
	}
	cout<<ans;
	
	return 0;
}
