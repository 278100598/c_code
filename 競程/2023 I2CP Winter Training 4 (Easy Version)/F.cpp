#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
string a,b;
vector<vector<char>> ans;
vector<char> now,cli;


void go(int x,int y) {
	if(y==b.size()) {
		ans.push_back(cli);
		return;
	}
	
	if(!now.empty() && now.back()==b[y]) {
		char tmp=now.back();
		now.pop_back();
		cli.push_back('o');
		go(x,y+1);
		cli.pop_back();
		now.push_back(tmp);
	}
	
	if(x!=a.size()) {
		now.push_back(a[x]);
		cli.push_back('i');
		go(x+1,y);
		cli.pop_back();
		now.pop_back();
	}
}

int main() {
	while(cin>>a>>b) {
		ans.clear();
		go(0,0);
		sort(ans.begin(),ans.end());
		
		cout<<"[\n";
		for(auto v:ans) {
			for(int i=0;i<v.size();i++) {
				if(i!=0) cout<<' ';
				cout<<v[i];
			}
			cout<<'\n';
		}
		cout<<"]\n";
	}
	
	return 0;
}
