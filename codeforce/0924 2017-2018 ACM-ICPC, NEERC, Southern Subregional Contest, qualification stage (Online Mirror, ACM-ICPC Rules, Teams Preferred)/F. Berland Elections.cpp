#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Candidate {
	int vote=0,last=-1,index;
}cs[101];

bool cmp(Candidate a,Candidate b) {
	if(a.vote != b.vote) return a.vote > b.vote;
	else return a.last < b.last;
}

int N,K,M,A,ans[101];

int main() {
	cin>>N>>K>>M>>A;
	for(int i=1;i<=N;i++) cs[i].index=i;
	for(int i=1;i<=A;i++) {
		int x;
		cin>>x;
		cs[x].vote++;
		cs[x].last = i;
	}
	
	sort(cs+1,cs+N+1,cmp);
	//for(int i=1;i<=N;i++) cout<<cs[i].index;
	
	for(int i=1;i<=N;i++) {
		int cnt=0,remain = M-A;
		Candidate &x = cs[i];
		for(int j=1;j<i;j++) {
			if(cs[j].vote >= x.vote + remain) cnt++;
		}
		if(cnt >= K || (remain == 0 && x.vote == 0)) {
			ans[x.index] = 3;
			continue;
		}
		
		cnt = 0;
		for(int j=i+1;j<=N;j++) {
			if(x.vote < cs[j].vote + remain) {
				remain -= (x.vote - cs[j].vote) + 1;
				cnt++;
			}
		}
		if(cnt + (i-1) < K && x.vote != 0) ans[x.index] = 1;
		else ans[x.index] = 2;
	}
	
	for(int i=1;i<=N;i++) cout<<ans[i]<<' ';
	
	return 0;
}
/*
3 2 5 4
1 3 3 1

*/
