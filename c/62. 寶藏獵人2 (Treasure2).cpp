#include<iostream>
#define mp make_pair
using namespace std;
int N,W,K,d[4001];
pair<int,int> item[2000];
int main() {
	cin>>N>>W>>K;
	d[0]=0;
	for(int i=1;i<=W+K;i++) d[i]=-1;
	for(int i=0;i<N;i++) cin>>item[i].first;
	for(int i=0;i<N;i++) cin>>item[i].second;
	
	for(int i=0;i<N;i++) {
		for(int j=W+K-item[i].first;j>=0;j--) {
			if(d[j]==-1) continue;
			if(d[j+item[i].first] == -1) d[j+item[i].first] = d[j]+item[i].second;
			else d[j+item[i].first] = min(d[j+item[i].first],d[j]+item[i].second);
		}
	}
	
	int mn=1e9;
	for(int i=max(0,W-K);i<=W+K;i++) {
		if(d[i]==-1) continue;
		mn=min(mn,d[i]);
	}
	if(mn==1e9) cout<<-1; 
	else cout<<mn;
	
	return 0;
}
