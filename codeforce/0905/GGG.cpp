#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
int N,M,d[5001],dd[5001];
vector<int> go;
string s;
bitset<26> st[5000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>M>>s;
	
	for(int i=0;i<N;i++) st[i]=0;
	for(int i=1;i<=M;i++) d[i]=-1;
	
	go.push_back(0);
	for(int i=0;i<M-1;i++) {
		bool y=true;
		for(int j=0;j<=i&&y;j++) {
			if(s[j] != s[(M-1-i)+j]) y=false;
		} 
		if(y) go.push_back(i+1);
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
	
	/*for(int j:go) {
		//if(i==j)continue;
		cout<<j<<endl;
	}*/
	
	d[0]=0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<=M;j++) dd[j]=-1;
		
		dd[0]=d[0]; 
		for(int j=0;j<M-1;j++) {
			if(d[j] == -1) continue;
			if(st[i][s[j]-'a']) {
				dd[j+1] = max(dd[j+1],d[j]);
				if(s[j] == s[0]) dd[1] = max(dd[1],d[j]);
			}
			
			dd[0]=max(dd[0],d[j]);
		}
		if(st[i][s[M-1]-'a'] && d[M-1] != -1) {
			for(int to:go) {
				dd[to] = max(dd[to],d[M-1]+1);
			}
		}
		
		for(int j=0;j<=M;j++) d[j] = dd[j];
		
		/*cout<<i<<"X"<<endl;
		for(int j=0;j<=M;j++) cout<<j<<" "<<d[j]<<endl;
		cout<<endl;*/
	}
	
	
	cout<<d[0];
	return 0;
}
/*
10 3
aca
3 a b c
2 a b
2 b c
2 a c
2 b c
2 a c
2 b c
2 b c
2 a b
2 a c
 
*/
