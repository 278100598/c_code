#include<iostream>
#include<math.h>
#include<algorithm>
#define x first
#define y second
#define Point pair<int,int>
#define endl '\n'
using namespace std;
int cross(Point o,Point a,Point b) {
	return (o.x-a.x) * (o.y-b.y) - (o.y-a.y) * (o.x-b.x);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int times;
	cin>>times;
	for(int tt=1;tt<=times;tt++) {
		int c,p;
		cin>>c>>p;
		Point points[c],tar[p];
		for(int i=0;i<c;i++) {
			cin>>points[i].x>>points[i].y;
		}
		for(int i=0;i<p;i++) {
			cin>>tar[i].x>>tar[i].y;
		}
		sort(points,points+c);
		/*
		for(int i=0;i<c;i++) {
			cout<<points[i].x<<" "<<points[i].y<<endl;
		}*/
		
		int up[c+1],low[c+1],ups=0,lows=0;
		for(int i=0;i<c;i++) {
			while(ups>=2&&cross(points[up[ups-2]],points[up[ups-1]],points[i])>=0) {
				ups--;
			}
			while(lows>=2&&cross(points[low[lows-2]],points[low[lows-1]],points[i])<=0) {
				lows--;
			}
			
			up[ups]=i;
			low[lows]=i;
			ups++;
			lows++;
		} 
		/*
		for(int i=0;i<ups;i++) {
			cout<<points[up[i]].x<<" "<<points[up[i]].y<<endl;
		}
		cout<<endl;
		for(int i=0;i<lows;i++) {
			cout<<points[low[i]].x<<" "<<points[low[i]].y<<endl;
		}*/
		
		bool y[p];
		for(int i=0;i<p;i++) {
			Point t = tar[i];
			y[i]=true;
			int upb=0,lowb=0;
			while(upb<ups-1) {
				if(points[up[upb]].x<=t.x && t.x<=points[up[upb+1]].x) break;
				upb++;
			}
			
			while(lowb<lows-1) {
				if(points[low[lowb]].x<=t.x && t.x<=points[low[lowb+1]].x) break;
				lowb++;
			}
			
			if(upb==ups-1||lowb==lows-1) {
				y[i]=true;
			}
			else if(cross(points[low[lowb]],points[low[lowb+1]],t) > 0 &&
					cross(points[up[upb]],points[up[upb+1]],t) < 0) {		
				y[i]=false;
			}
			else {
				y[i]=true;
			}
		}
		
		/*
		for(int i=0;i<p;i++) {
			cout<<y[i]<<endl;
		}*/
		
		cout<<"Case "<<tt<<endl;
		for(int i=0;i<lows;i++) {
			cout<<points[low[i]].x<<" "<<points[low[i]].y<<endl;
		}
		for(int i=ups-2;i>=0;i--) {
			cout<<points[up[i]].x<<" "<<points[up[i]].y<<endl;
		}
		for(int i=0;i<p;i++) {
			cout<<tar[i].x<<" "<<tar[i].y;
			if(y[i])cout<<" is safe!"<<endl;
			else cout<<" is unsafe!"<<endl;
		}
		if(tt<times)cout<<endl;
	}
	return 0;
}
