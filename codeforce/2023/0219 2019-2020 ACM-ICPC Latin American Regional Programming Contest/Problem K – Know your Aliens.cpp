#include<bits/stdc++.h>
#define int long long
using namespace std;
string S;
vector<int> factor,cal,t;


signed main() {
	cin>>S;
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	
	for(int i=1;i<S.size();i++) {
		if(S[i]!=S[i-1]) factor.push_back(i*2+1);
	}
	
	cal.push_back(1);
	for(int i=0;i<factor.size();i++) {
		int x=-factor[i];
		cal.push_back(cal.back());
		for(int j=cal.size()-2;j>=1;j--) {
			cal[j]=cal[j]*x+cal[j-1];
		}
		cal[0]*= x;
	}
	
	cout<<cal.size()-1<<'\n';
	for(int i=cal.size()-1;i>=0;i--) {
		if(S.back()=='A') cout<<-cal[i]<<' ';
		else cout<<cal[i]<<' ';
	}
	
	return 0;
}
