#include<iostream>
#include<math.h>
#include<queue>
#include<string>
#include<iomanip>
using namespace std;
struct Point {
	int x,y;
};
Point all[5];
priority_queue<pair<double,string>,vector<pair<double,string>>,greater<pair<double,string>>>pq;
double getdis(Point a,Point b) {
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
void bfs(int index,string s,double dis) {
	if(index==5) {
		pq.push(pair<double,string>(dis,s));
		return;
	}
	for(int i=1;i<=4;i++) {
		if(s.find(to_string(i))==string::npos) {
			bfs(index+1,s+to_string(i),dis+getdis(all[s[s.size()-1]-'0'],all[i]));
		}
	}
}
int main() {
	all[0].x=0;
	all[0].y=0;
	for(int i=1;i<=4;i++) {
		cin>>all[i].x>>all[i].y;
	}
	for(int i=1;i<=4;i++) {
		bfs(2,"0"+to_string(i),getdis(all[0],all[i]));
	}
	cout<<fixed<<setprecision(2)<<pq.top().first<<endl<<pq.top().second;
	return 0;
}
