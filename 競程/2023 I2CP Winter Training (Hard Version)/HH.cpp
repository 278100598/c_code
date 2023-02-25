#include<iostream>
using namespace std;
string a,b,s;
int T,H,W,N,dp[20001],tmp[20001];
char m[30][30];

int lcs() {
	//cout<<a<<' '<<b<<'\n';
	swap(a,b);
	for(int i=0;i<=b.size();i++) dp[i]=0;
	tmp[0]=0;
	for(int i=0;i<a.size();i++) {
		for(int j=1;j<=b.size();j++) {
			if(b[j-1]==a[i]) tmp[j]=dp[j-1]+1;
			else tmp[j] = max(dp[j],tmp[j-1]);
		}
		for(int j=1;j<=b.size();j++) dp[j]=tmp[j];
	}
	swap(a,b);
	
	return dp[a.size()];
}

int main() {
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
