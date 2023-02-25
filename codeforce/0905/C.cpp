#include<iostream>
#include<queue>
#include<string.h>
#define LL long long int
#define MAXN 502
#define keep kp
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;// 1-base，0表示沒有匹配 
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

int N,M,x[500][500];
int main() {
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>x[i][j];
		}
	}
	
	int i1=1,keep=0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(x[i][j]>1) {
				
				for(int z=2;z<=x[i][j];z++) {
					int i2=1;
					for(int ii=0;ii<N;ii++) {
						for(int jj=0;jj<M;jj++) {
							if(x[ii][jj]==0) {
								g[i1][i2] = -abs(i-ii) - abs(j-jj);
								i2++;
							}
						}
					}
					i1++;
					keep = i2-1;
				}
				
			}
		}
	}
	
	
	for(;i1<keep;i1++) {
		int i2=1;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(x[i][j]==0) {
					g[i1][i2] = 0;
					i2++;
				}
			}
		}
		i1++;
	}
	
	/*
	for(int i=1;i<=keep;i++) {
		for(int j=1;j<=keep;j++) {
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	n=keep;
	cout<<-KM();
	
	return 0;
}

