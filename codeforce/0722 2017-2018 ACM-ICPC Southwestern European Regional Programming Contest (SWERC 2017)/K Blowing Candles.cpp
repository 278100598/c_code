#include<iostream>
#include<algorithm>
#include<math.h>
#include<iomanip>
#define Ps pair<long long int,long long int>
#define x first
#define y second
using namespace std;
int *sop,sops=0,N,R;
Ps *point;

long long int cross(Ps o,Ps a,Ps b) {
	return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}
double dis(Ps a,Ps b) {
	double res=(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	return sqrt(res);
}

double find(int a,int b,int &index) {
	double x=abs(cross(point[a],point[b],point[sop[index]]));
	
	while(abs(cross(point[a],point[b],point[sop[(index+1)%sops]])) >= x) {
		x=abs(cross(point[a],point[b],point[sop[(index+1)%sops]]));
		index = (index+1)%sops;
	}
	
	//cout<<fixed<<x<<" "<<dis(point[a],point[b])<<endl;
	return x/dis(point[a],point[b]);
}

int main() {
	cin>>N>>R;
	point = new Ps[N];
	for(int i=0;i<N;i++) {
		cin>>point[i].x>>point[i].y;
	}
	
	sort(point,point+N);
	int up[N],low[N],ups=0,lows=0;
	
	for(int i=0;i<N;i++) {
		while(ups>=2&&cross(point[up[ups-2]],point[up[ups-1]],point[i])>=0) {
			ups--;
		}
		while(lows>=2&&cross(point[low[lows-2]],point[low[lows-1]],point[i])<=0) {
			lows--;
		}
		up[ups]=i;
		low[lows]=i;
		ups++;
		lows++;
	}
	
	sop = new int[N];
	for(int i=0;i<ups-1;i++) {
		sop[sops]=up[i];
		sops++;
	}
	for(int i=lows-1;i>0;i--) {
		sop[sops]=low[i];
		sops++;
	}
	
	if(sops<=2) {
		cout<<"0.000000"<<endl;
		return 0;
	}
	
	int index=1;
	double mn=find(sop[sops-1],sop[0],index);
	
	for(int i=1;i<sops;i++) {
		mn = min(mn,find(sop[i-1],sop[i],index));
	}
	cout<<fixed<<setprecision(16)<<mn<<endl;
	
	/*
	for(int i=0;i<ups;i++) {
		cout<<point[up[i]].x<<" "<<point[up[i]].y<<endl;
	}
	cout<<endl;
	for(int i=0;i<lows;i++) {
		cout<<point[low[i]].x<<" "<<point[low[i]].y<<endl;
	}
	for(int i=0;i<sops;i++) {
		cout<<point[sop[i]].x<<" "<<point[sop[i]].y<<endl;
	}*/
	return 0;
}
/*
4 100
0 0
2 2
1 1
5 1*/
