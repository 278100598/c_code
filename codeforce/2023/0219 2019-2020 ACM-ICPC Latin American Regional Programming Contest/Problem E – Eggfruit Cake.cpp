#include<bits/stdc++.h>
using namespace std;
string B;
int S;

int main() {
	cin>>B>>S;
	
	int l=-1;
	for(int i=B.size()-1;i>=0;i--) {
		if(B[i]=='E') {
			l=i;
			break;
		}
	}
	if(l==-1) {
		cout<<0;
		return 0;
	}
	
	
	long long int ans = 0;
	for(int i=0;i<B.size();i++) {
		if(B[i]=='E') l=i;
		if((i+B.size()-l)%B.size() < S)  ans += S - ((i+B.size()-l)%B.size());
	}
	
	cout<<ans;
	return 0;
}
