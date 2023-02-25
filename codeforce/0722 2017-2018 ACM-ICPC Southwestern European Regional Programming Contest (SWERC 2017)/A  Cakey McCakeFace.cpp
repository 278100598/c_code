#include<iostream>
#include<map>
using namespace std;
int main() {
	int N,M;
	map<int,int>time;
	cin>>N>>M;
	int cakein[N],cakeout[M];
	for(int i=0;i<N;i++) {
		cin>>cakein[i];
	}
	for(int i=0;i<M;i++) {
		cin>>cakeout[i];
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(cakeout[j]>=cakein[i]) {
				time[cakeout[j]-cakein[i]]++;
			}
		}
	}
	
	int mx=0,ans=0;
	for(auto it=time.begin();it!=time.end();it++) {
		if(it->second>mx) {
			mx=it->second;
			ans=it->first;
		}
	}
	cout<<ans;
	return 0;
} 
