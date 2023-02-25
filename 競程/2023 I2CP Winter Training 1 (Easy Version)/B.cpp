#include<iostream>
#include<vector>
using namespace std;
vector<string> x;
string s;

int main() {
	int mx=0;
	while(getline(cin,s)) {
		x.push_back(s);
		mx = max(mx,(int)s.size());
	}
	
	for(int i=0;i<mx;i++) {
		for(int j=x.size()-1;j>=0;j--) {
			if(x[j].size() > i) cout<<x[j][i];
			else cout<<' ';
		}
		cout<<'\n';
	}
	
	
	return 0;
}
