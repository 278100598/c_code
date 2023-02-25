#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
int N,M,d[5001],dd[5001];
vector<int> go[5001];
string s;
bitset<26> st[5000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>M>>s;
	
	for(int i=0;i<N;i++) st[i]=0;
	for(int i=0;i<=M;i++) d[i]=-1;
	
	go[0].push_back(0);
	for(int i=1;i<=M;i++) {
		go[i].push_back(0);
		for(int t:go[i-1]) {
			if(s[t] == s[i-1]) go[i].push_back(t+1);
		}
	}
	
	for(int i=0;i<N;i++) {
		int k;
		cin>>k;
		for(int j=0;j<k;j++) {
			char c;
			cin>>c;
			st[i][c-'a']=true;
		}
	}
	
	/*for(int i=0;i<=M;i++) {
		cout<<i<<"X";
		for(int j:go[i]) {
			//if(i==j)continue;
			cout<<" "<<j;
		}
		cout<<endl;
	}*/
	
	d[0]=0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<=M;j++) dd[j]=-1;
		
		dd[0]=d[0];
		for(int j=0;j<M;j++) {
			if(d[j] == -1) continue;
			if(st[i][s[j]-'a']) {
				if(j+1==M) d[j]++;
				
				for(int to:go[j+1]) {
					dd[to] = max(dd[to],d[j]);
				}
				/*if(!go[j+1].empty()) {
					int to=go[j+1].back();
					if(to==M) to=go[j+1][go[j+1].size()-2];
					dd[to] = max(dd[to],d[j]);
				}*/
			}
		}
		
		for(int j=0;j<=M;j++) d[j] = dd[j];
		
		/*cout<<i<<"X"<<endl;
		for(int j=0;j<=M;j++) cout<<j<<" "<<d[j]<<endl;
		cout<<endl;*/
	}
	
	int mx=0;
	for(int i=0;i<=M;i++) mx=max(d[i],mx);
	cout<<mx;
	return 0;
}
/*
1 10
abacabacab
2 a b
*/
