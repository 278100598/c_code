#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;
string a,b;
char m[30][30];
int T,H,W,N;


int lcs() {
	//cout<<a<<' '<<b<<'\n';
	vector<int> vv[128];
	for(int i=0;i<a.size();i++) vv[a[i]].push_back(i);
	
	vector<int> v;
	for(int i=0;i<b.size();i++) {
		for(int j=vv[b[i]].size()-1;j>=0;j--) {
			int x=vv[b[i]][j];
			
			auto it = lower_bound(v.begin(),v.end(),x);
			if(it == v.end()) v.push_back(x);
			else *it=x;
		}
	}
	return v.size();
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin>>T;
	for(int turn=1;turn<=T;turn++) {
		cin>>H>>W;
		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++) cin>>m[i][j];
		}
		
		int x,y;
		cin>>N>>x>>y;
		a="";
		a+=m[x-1][y-1];
		for(int i=0;i<N;i++) {
			char c;
			cin>>c;
			if(c=='N') x--;
			else if(c=='E') y++;
			else if(c=='S') x++;
			else if(c=='W') y--;
			a+=m[x-1][y-1];
		}
		
		cin>>N>>x>>y;
		b="";
		b+=m[x-1][y-1];
		for(int i=0;i<N;i++) {
			char c;
			cin>>c;
			if(c=='N') x--;
			else if(c=='E') y++;
			else if(c=='S') x++;
			else if(c=='W') y--;
			b+=m[x-1][y-1];
		}
		
		int ret=lcs();
		cout<<"Case "<<turn<<": "<<a.size()-ret<<' '<<b.size()-ret<<'\n';
	}
	
	
	return 0;
}
