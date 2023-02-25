#include<iostream>
using namespace std;
long long int T,n,m;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	while(T--) {
		cin>>m>>n;
		if(m==1) {
			if(n==0) cout<<1<<endl;
			else cout<<2<<endl;
			continue;
		}
		long long int x=(1LL<<m);
		if(n==0) cout<<x<<endl;
		else cout<<x-1<<endl;
	}
	return 0;
}
