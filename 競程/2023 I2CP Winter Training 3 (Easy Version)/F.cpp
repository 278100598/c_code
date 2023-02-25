#include<iostream>
#include<vector>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int T,N;
string a,b;
vector<pii> ans;

int main() {
	cin>>T;
	while(T--) {
		cin>>N>>a>>b;
		ans.clear();
		int sum=0;
		bool same=true,rev=true;
		for(int i=0;i<a.size();i++) {
			if(a[i]=='1') sum++;
			if(a[i]==b[i]) rev=false;
			if(a[i]!=b[i]) same=false;
		}
		
		if(!rev && !same) {
			cout<<"NO\n";
			continue;
		}
		
		if(rev) {
			for(int i=0;i<a.size();i++) {
				if(a[i]=='0') a[i]='1';
				else a[i]='0';
			}
			ans.push_back(pii(1,N));
			sum = N-sum;
		}
		
		for(int i=0;i<a.size();i++) {
			if(a[i]=='1') ans.push_back(pii(i+1,i+1));
		}
		if(sum%2==1) {
			ans.push_back(pii(1,N));
			ans.push_back(pii(1,1));
			ans.push_back(pii(2,N));
		}
		
		
		cout<<"YES\n";
		cout<<ans.size()<<'\n';
		for(pii it:ans) cout<<it.ff<<' '<<it.ss<<'\n';
		
	}
	
	return 0;
}
