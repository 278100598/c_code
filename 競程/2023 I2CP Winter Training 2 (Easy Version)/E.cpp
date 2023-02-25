#include<iostream>
#include<vector>
#include<map>
using namespace std;
int T;
string a,b;
map<string,string> x,y;

map<string,string> parse(string s) {
	map<string,string> m;
	string k="",v="";
	int tag=0;
	
	for(int i=1;i<s.size()-1;i++) {
		if(s[i]==':') tag=1;
		else if(s[i]==',') {
			m[k]=v;
			k="";
			v="";
			tag=0;
		} else {
			if(tag) v+=s[i];
			else k+=s[i];
		}
	}
	if(!k.empty()) m[k]=v;
	return m;
}

int main() {
	//freopen("out.txt","w",stdout);
	cin>>T;
	while(T--) {
		cin>>a>>b;
		x = parse(a);
		y = parse(b);
		
		vector<string> add,sub,mov;
		for(auto i:x) {
			auto it = y.find(i.first);
			if(it == y.end()) sub.push_back(i.first);
			else if(i.second != it->second) mov.push_back(i.first);
		}
		for(auto i:y) {
			auto it = x.find(i.first);
			if(it == x.end()) add.push_back(i.first);
		}
		
		if(add.empty() && sub.empty() && mov.empty()) cout<<"No changes\n";
		else {
			if(!add.empty()) {
				cout<<'+'<<add[0];
				for(int i=1;i<add.size();i++) cout<<','<<add[i];
				cout<<'\n';
			}
			if(!sub.empty()) {
				cout<<'-'<<sub[0];
				for(int i=1;i<sub.size();i++) cout<<','<<sub[i];
				cout<<'\n';
			}
			if(!mov.empty()) {
				cout<<'*'<<mov[0];
				for(int i=1;i<mov.size();i++) cout<<','<<mov[i];
				cout<<'\n';
			}
		}
		
		cout<<'\n';
	}
	
	return 0;
}
