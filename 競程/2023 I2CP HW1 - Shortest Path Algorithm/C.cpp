#include<bits/stdc++.h>
using namespace std;
struct Edge {
	long long int u,v,w;
	Edge(){}
	Edge(int a,int b,int c) {
		u=a;v=b;w=c;
	}
}E[2000];

int N,M;
long long int dis[1001];

int main() {
	cin>>N>>M;
	dis[1]=0;
	for(int i=2;i<=N;i++) dis[i]=-1e18;
	for(int i=0;i<M;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		E[i]=Edge(a,b,c);
	}
	
	for(int i=1;i<=N;i++) {
		for(int j=0;j<M;j++) {
			Edge &e = E[j];
			dis[e.v] = max(dis[e.v],dis[e.u]+e.w);
		}
	}
	
	long long int tmp = dis[N];
	
	for(int i=1;i<=N;i++) {
		for(int j=0;j<M;j++) {
			Edge &e = E[j];
			dis[e.v] = max(dis[e.v],dis[e.u]+e.w);
		}
	}
	
	if(tmp==dis[N]) cout<<dis[N];
	else cout<<"inf";
	
	return 0;
}
