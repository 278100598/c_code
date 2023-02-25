#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

#define LL long long int
#define MAXN 405
#define INF 0x3f3f3f3f3f3f3f3f
int n;// 1-base�A0��ܨS���ǰt 
LL g[MAXN][MAXN]; //input graph
int My[MAXN],Mx[MAXN]; //output match
LL lx[MAXN],ly[MAXN],pa[MAXN],Sy[MAXN];
bool vx[MAXN],vy[MAXN];
void augment(int y){
	for(int x, z; y; y = z){
		x=pa[y],z=Mx[x];
		My[y]=x,Mx[x]=y;
	}
}
void bfs(int st){
	for(int i=1; i<=n; ++i)
		Sy[i] = INF, vx[i]=vy[i]=0;
	queue<int> q; q.push(st);
	for(;;){
		while(q.size()){
			int x=q.front(); q.pop();
			vx[x]=1;
			for(int y=1; y<=n; ++y) if(!vy[y]){
				LL t = lx[x]+ly[y]-g[x][y];
				if(t==0){
					pa[y]=x;
					if(!My[y]){augment(y);return;}
					vy[y]=1,q.push(My[y]);
				}else if(Sy[y]>t) pa[y]=x,Sy[y]=t;
			}
		}
		LL cut = INF;
		for(int y=1; y<=n; ++y)
			if(!vy[y]&&cut>Sy[y]) cut=Sy[y];
		for(int j=1; j<=n; ++j){
			if(vx[j]) lx[j] -= cut;
			if(vy[j]) ly[j] += cut;
			else Sy[j] -= cut;
		}
		for(int y=1; y<=n; ++y){
			if(!vy[y]&&Sy[y]==0){
				if(!My[y]){augment(y);return;}
				vy[y]=1, q.push(My[y]);
			}
		}
	}
}
LL KM(){
	memset(My,0,sizeof(int)*(n+1));
	memset(Mx,0,sizeof(int)*(n+1));
	memset(ly,0,sizeof(LL)*(n+1));
	for(int x=1; x<=n; ++x){
		lx[x] = -INF;
		for(int y=1; y<=n; ++y)
			lx[x] = max(lx[x],g[x][y]);
	}
	for(int x=1; x<=n; ++x) bfs(x);
	LL ans = 0;
	for(int y=1; y<=n; ++y) ans+=g[My[y]][y];
	return ans;
}

int N;
int node[502][502];

int main() {
	cin>>N;
	n=(N+1)/2;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>node[i][j];
		}
	}
	for(int i=1;i*2-1<=N;i++) {
		for(int j=1;j*2<=N;j++) {
			g[i][j] -= node[i*2-1][j*2];
			if(j*2!=N) g[i][j+1] -= node[i*2-1][j*2];
		}
	}
	
	/*for(int i=1;i<=n+1;i++) {
		for(int j=1;j<=n;j++) {
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	cout<<-KM();
	return 0;
}
