#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define pdd pair<double,double>
#define pid pair<int,double>
#define mp make_pair
#define ff first
#define ss second
using namespace std;
int N,L,W,ans[100000];
double eps=1e-7;
struct Rain {
	double c,ra,l,r;
	Rain(int a,int b) {
		c=a;
		ra=b;
		double d = sqrt(ra*ra-W*W/4.);
		l=c-d;
		r=c+d;
	}
	bool operator < (Rain &a) {
		return l<a.l;
	}
};

bool touch(Rain a,Rain b) {
	
}

vector<Rain> water;

int main() {
	//freopen("out.txt","w",stdout);
	while(cin>>N>>L>>W) {
		water.clear();
		for(int i=0;i<N;i++) {
			int a,b;
			cin>>a>>b;
			if(b*2>=W) water.emplace_back(a,b);
			
		}
		sort(water.begin(),water.end());
		
		priority_queue<pid,vector<pid>,greater<pid>> pq;
		pq.push(mp(0,0));
		for(int i=0;i<water.size();i++) ans[i]=-1;
		for(int i=0;i<water.size();i++) {
			while(!pq.empty() && pq.top().ss+eps < water[i].l) pq.pop();
			//cout<<pq.top().ff<<' '<<pq.top().ss<<' '<<water[i].l<<'\n';
			if(pq.empty()) break;
			
			pq.push(mp(pq.top().ff+1,water[i].r));
			ans[i]=pq.top().ff+1;
		}
		
		int mn=1e9;
		for(int i=0;i<water.size();i++) {
			if(L <= water[i].r+eps && ans[i]!=-1) {
				mn = min(ans[i],mn);
			} 
		}
		
		if(mn == 1e9) cout<<-1<<'\n';
		else cout<<mn<<'\n';
	}
	
	return 0;
}
