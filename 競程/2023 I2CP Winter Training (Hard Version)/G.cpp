#include<iostream>
#include<queue>
using namespace std;
const int MX=100;
int lx[MX],ly[MX],p[MX],mx[MX],my[MX],sy[MX],w[MX][MX];
int N,D,R,up[MX],low[MX];
bool vx[MX],vy[MX];
void back(int y) {
	while(true) {
		int x=p[y],t=mx[x];
		my[y]=x;
		mx[x]=y;
		
		if(t==-1) return;
		y=t;
	}
}

void bfs(int s) {
	for(int i=0;i<N;i++) {
		sy[i]=1e9;
		vx[i]=false;
		vy[i]=false;
	}
		
	queue<int> q;
	q.push(s);
	while(true) {
		while(!q.empty()) {
			int x=q.front();
			q.pop();
			vx[x] = true;
			
			for(int y=0;y<N;y++) {
				if(vy[y]) continue;
				int dif=lx[x]+ly[y]-w[x][y];
				if(dif==0) {
					p[y]=x;
					if(my[y]==-1) {
						back(y);
						return;
					}
					vy[y]=true;
					q.push(my[y]);
				} else if(dif < sy[y]) {
					p[y]=x;
					sy[y]=dif;
				}
			}
		}
		
		int mn=1e9;
		for(int y=0;y<N;y++) {
			if(!vy[y]) mn=min(mn,sy[y]);
		}
		for(int i=0;i<N;i++) {
			if(vx[i]) lx[i]-=mn;
			if(vy[i]) ly[i]+=mn;
			else sy[i]-=mn;
		}
		
		for(int y=0;y<N;y++) {
			if(!vy[y] && sy[y]==0) {
				if(my[y]==-1) {
					back(y);
					return;
				}
				vy[y]=true;
				q.push(my[y]);
			}
		}
	}
}


int main() {
	while(cin>>N>>D>>R) {
		if(N==0 && D==0 && R==0) break;
		for(int i=0;i<N;i++) cin>>up[i];
		for(int i=0;i<N;i++) cin>>low[i];
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				w[i][j] = -max(0,up[i]+low[j]-D);
			}
		}
		
		for(int i=0;i<N;i++) {
			mx[i]=-1;
			my[i]=-1;
			lx[i]=-1e9;
			ly[i]=0;
			for(int j=0;j<N;j++) lx[i] = max(w[i][j],lx[i]);
		}
		
		for(int i=0;i<N;i++) bfs(i);
		
		int sum=0;
		for(int i=0;i<N;i++) sum-=w[i][mx[i]];
		cout<<sum*R<<'\n';
	}
	
	return 0;
}
/*
4 10 1
10 15 5 6
10 15 5 8
*/
