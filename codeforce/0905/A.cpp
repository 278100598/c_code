#include<iostream>
#define F first
#define S second
using namespace std;
pair<int,int> l[3],r[3];
int main() {
	for(int i=0;i<3;i++) cin>>l[i].F>>l[i].S>>r[i].F>>r[i].S;
	
	int fx = l[0].first,fy = l[0].second;
	for(int i=1;i<=2;i++) {
		fx = max(l[i].first,fx);
		fy = max(l[i].second,fy);
	}
	
	int sx = r[0].first,sy = r[0].second;
	for(int i=1;i<=2;i++) {
		sx = min(r[i].first,sx);
		sy = min(r[i].second,sy);
	}
	
	long long int x=sx-fx,y=sy-fy;
	if(x<=0 || y<=0) cout<<0;
	else cout<<x*y;
	return 0;
} 
