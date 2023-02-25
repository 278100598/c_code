#include<iostream>
#pragma GCC optimize("O3")
#define endl '\n'
using namespace std;
int team[30],N,Q;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>N>>Q;
	for(int i=0;i<30;i++) team[i]=1;
	for(int i=1;i<=N;i++) {
		long long int x;
		cin>>x;
		for(int j=0;j<30;j++) {
			if(!(x&1)) team[j] = i+1;
			x=x>>1;
		}
	}
	
	for(int i=0;i<Q;i++) {
		long long int a,b;
		cin>>a>>b;
		if(a==1) {
			long long int ans=0;
			for(int j=29;j>=0;j--) {
				ans=ans<<1;
				if(team[j] <= b) ans++;
			}
			cout<<ans<<endl;
		} else if(a==2) {
			N++;
			for(int j=0;j<30;j++) {
				if(!(b&1)) team[j] = N+1;
				b=b>>1;
			}
		}
	} 
	return 0;
}
