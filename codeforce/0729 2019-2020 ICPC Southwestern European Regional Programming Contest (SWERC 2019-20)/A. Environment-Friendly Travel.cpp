#include<iostream>
#include<Math.h>
#include<vector>
#include<set>
using namespace std;
#define mp make_pair
typedef pair<int,pair<int,int>> PIII;
#define F first
#define S second

struct Point {
    int x=-1,y=-1,cost=0;
    bool vis;
    vector<pair<int,int> > go_co2;
};

int dis(Point a, Point b) {
	return ceil(sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)));
}

int T,N,B,co2[101];
Point home,des,tans[10001];
set<PIII> pq;
vector<PIII> edge;

int main() {
	//freopen("test6.in","r",stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>home.x>>home.y;
	cin>>des.x>>des.y;
	cin>>B>>co2[0]>>T;
	for(int i=1;i<=T;i++) cin>>co2[i];
	
	cin>>N;
	for(int i=0;i<N;i++) {
		int num;
		cin>>tans[i].x>>tans[i].y>>num;
		for(int j=0;j<num;j++) {
			int to,way;
			cin>>to>>way;
			edge.push_back(mp(co2[way],mp(i,to)));
		}
	}
	tans[N].x=des.x;
	tans[N].y=des.y;
	
	for(PIII it:edge) {
		int cost=it.F,a=it.S.F,b=it.S.S;
		tans[a].go_co2.push_back(mp(b,cost*dis(tans[a],tans[b])));
		tans[b].go_co2.push_back(mp(a,cost*dis(tans[a],tans[b])));
	}
	for(int i=0;i<N;i++) {
		tans[i].go_co2.push_back(mp(N,co2[0]*dis(tans[i],tans[N])));
	}
	
	for(int i=0;i<=N;i++) {
		int d=dis(home,tans[i]);
		if(d <= B) {
			pq.insert(mp(d*co2[0],mp(d,i)));
		}
	}
	
	while(!pq.empty()) {
		if(pq.begin()->S.S==N) {
			cout<<pq.begin()->F;
			return 0;
		}
		int co2=pq.begin()->F,index=pq.begin()->S.S,d=pq.begin()->S.F;
		pq.erase(pq.begin());
		Point &p=tans[index];
		//if(p.vis)cout<<d<<" "<<p.cost<<endl;
		if(p.vis && d>=p.cost) continue;
		p.cost=d;
		p.vis=true;
		
		//cout<<co2<<" "<<index<<" "<<d<<endl;
		for(auto i:p.go_co2) {
			int to=i.first,cost=i.second;
			int newd=d+dis(p,tans[to]), newco2=co2+cost;
			if(newd + dis(tans[to],des) <= B) {
				pq.insert(mp(newco2,mp(newd,to)));
			}
		}
	}
	cout<<-1;
	return 0;
}


