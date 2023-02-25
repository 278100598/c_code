#include<iostream>
using namespace std;
const int MX=1000000;
bool prime[MX+1];

bool check(int x) {
	string s=to_string(x);
	for(int i=0;i<s.size();i++) {
		if(!prime[stoi(s)]) return false;
		char c=s[0];
		s.erase(0,1);
		s += c;
	}
	return true;
}

int pre[MX+1];

int main() {
	for(int i=3;i<=MX;i+=2) prime[i]=true;
	
	for(int i=3;i<=MX;i+=2) {
		for(int j=i*2;j<=MX;j+=i) {
			if(prime[j]) {
				prime[j]=false;
			}
		}
	}
	
	for(int i=1;i<=MX;i++) {
		pre[i]=pre[i-1];
		if(check(i)) pre[i]++;
	}
	
	int l,r;
	while(cin>>l) {
		if(l==-1) break;
		cin>>r;
		
		int ans=pre[r]-pre[l-1];
		if(ans==0) cout<<"No Circular Primes.\n";
		else if(ans==1) cout<<"1 Circular Prime.\n";
		else cout<<ans<<" Circular Primes.\n";
	}
	
	return 0;
} 
