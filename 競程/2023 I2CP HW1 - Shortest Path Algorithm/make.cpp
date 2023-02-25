#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int r(int min,int max) {
	int a = rand()%10000,b = rand()%10000,c = rand()%10;
	int d=a*100000+b*10+c;
	return d%(max-min+1)+min;
}
long long int llr(long long int min,long long int max) {
	long long int a=r(0,1e9-1),b=r(0,1e9-1);
	long long int c=a*1e9+b;
	return c%(max-min+1)+min;
}

set<pii> st;
int N=10,M=50;


int main() {
	for(int i=2;i<=N;i++) st.insert(pii(i-1,i));
	while(st.size()<M) st.insert(pii(r(1,N),r(1,N)));
	
	cout<<N<<' '<<M<<'\n';
	for(pii p:st) {
		cout<<p.ff<<' '<<p.ss<<' '<<llr(-1e9,1e9)<<'\n';
	}
	
	return 0;
}
