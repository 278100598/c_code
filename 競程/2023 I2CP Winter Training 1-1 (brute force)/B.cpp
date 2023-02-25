#include<iostream>
#include<vector>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int K;
vector<pii> ans; 


int main() {
	while(cin>>K) {
		ans.clear();
		for(int x=K+1;x<=2*K;x++) {
			int ya=x-K,yb=x*K;
			if(yb%ya==0) ans.push_back(pii(yb/ya,x));
		}
		
		cout<<ans.size()<<'\n';
		for(auto it:ans) printf("1/%d = 1/%d + 1/%d\n",K,it.ff,it.ss);
		
	}
	
	return 0;
}
