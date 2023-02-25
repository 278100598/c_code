#include<iostream>
#include<map>
#define mp make_pair
#define F first
#define S second
using namespace std;
int N,X,Y;
map<int,pair<int,int>> m,cnt;

int main() {
	cin>>X>>Y>>N;
	long long int sum=0,low=0;
	for(int i=0;i<N;i++) {
		int x,y;
		cin>>x>>y;
		
		if(m.find(x) != m.end()) {
			m[x].F = min(m[x].F,y);
			m[x].S = max(m[x].S,y); 
		} else {
			m[x] = mp(y,y);
		}
	}
	
	for(int i=0;i<=X;i++) {
		if(m.find(i) != m.end()) {
			cnt[m[i].F].F++;
			cnt[m[i].S].S++;
			sum += m[i].S;
			low++;
			//cout<<i<<' '<<m[i].F<<' '<<m[i].S<<'\n';
		}
	}
	
	//cout<<low<<'\n';
	long long int mn=sum,up=0;
	for(int i=1;i<=Y;i++) {
		//cout<<cnt[i-1].F<<' '<<cnt[i-1].S<<'\n';
		up+=cnt[i-1].F;
		low-=cnt[i-1].S;
		
		
		sum += up;
		sum -= low;
		
		//cout<<i<<' '<<sum<<' '<<up<<' '<<low<<'\n';
		mn = min(sum,mn);
	}
	cout<<mn*2+(X-1);
	
	return 0;
}
/*
5 7
5
0 0
1 0
2 0
3 0
4 0
*/
