#include<iostream>
#include<map>
using namespace std;
map<char,int>m;
int total=0;
string s;
void dfs(string ss) {
	if(ss.size()==s.size()) {
		total++;
		return;
	}
	for(auto it = m.begin();it != m.end();it++) {
		if(ss[ss.size()-1]!=it->first&&it->second>0) {
			it->second--;
			dfs(ss+it->first);
			it->second++;
		}
	}
}
int main() {
	int n;
	cin>>n>>s;
	for(int i=0;i<n;i++) {
		m[s[i]]++;
	}
	for(auto it = m.begin();it != m.end();it++) {
		it->second--;
		dfs(string(1,it->first));
		it->second++;
	}
	cout<<total;
	return 0;
}
