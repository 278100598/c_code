#include<iostream>
#include<map>
#define pii pair<int,int>
using namespace std;
int N,K,num[500000],dis[500000];

int cal(int x) {
	int limit=1e9,sum=1;
	for(int i=0;i<N;i++) {
		if(dis[i] > x && dis[i] <= limit) {
			sum++;
			limit = 0;
		}
		limit++;
	}
	return sum;
	
}

int main() {
	cin>>N>>K;
	for(int i=0;i<N;i++) cin>>num[i];
	
	map<int,int> mp;
	
	for(int i=0;i<N;i++) {
		auto it=mp.upper_bound(num[i]);
		if(it->first > num[i]) {
			dis[i]= i - it->second;
		} else dis[i]=0;
		
		if(mp.find(num[i])->first != num[i]) mp[num[i]] = i;
	}
	//for(int i=0;i<N;i++) cout<<dis[i]<<endl;
	
	int ans=0,l=0,r=N;
	/*while(true) {
		int m=(l+r)/2;
		
		int sum = cal(m);
		
		//cout<<l<<" "<<m<<" "<<r<<" "<<sum<<endl;
		if(K < sum) l=m+1;
		else if(sum <= K) r=m;
		if(l==r) {
			ans=r;
			break;
		}
	}*/
	for(int i=0;i<=N;i++) {
		if(cal(i) <= K) {
			ans=i;
			break;
		}
	}
	
	cout<<K<<" "<<cal(ans+2);
	/*for(int i=0;i<=N;i++) {
		cout<<i<<" "<<cal(i)<<endl;
	}*/
	cout<<ans<<endl;
	
	return 0;
}
/*
10 1
1 2 2 1 2 1 1 1 1 1
9 1
4 1 2 5 0 9 12 8 9
*/
