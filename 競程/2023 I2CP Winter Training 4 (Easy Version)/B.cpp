#include<iostream>
using namespace std;
int T,N;

int main() {
	cin>>T;
	while(T--) {
		cin>>N;
		int mn=1e9,mx=-1e9;
		for(int i=0;i<N;i++) {
			int x;
			cin>>x;
			mn = min(mn,x);
			mx = max(mx,x);
		}
		
		cout<<(mx-mn)*2<<'\n';
	}
	
	return 0;
}
