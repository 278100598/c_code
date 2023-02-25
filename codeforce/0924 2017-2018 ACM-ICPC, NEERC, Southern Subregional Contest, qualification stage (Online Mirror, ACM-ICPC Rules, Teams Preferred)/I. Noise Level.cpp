#include<iostream>
#include<queue>
#define F first
#define S second
#define mp make_pair
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
int N,M,Q,P,level[26];
char keep[251][251];
bool vis[251][251];
long long int all[251][251];
queue<pair<pair<int,int>,int>> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>N>>M>>Q>>P;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) cin>>keep[i][j];
	}
	for(int i=0,j=Q;i<26;i++,j+=Q) level[i] = j;
	
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if('A' <= keep[i][j] && keep[i][j] <= 'Z') {
				
				for(int i=1;i<=N;i++) {
					for(int j=1;j<=M;j++) vis[i][j] = false;
				}
				q.push(mp(mp(i,j),level[keep[i][j]-'A']));
				vis[i][j] = true;
				
				while(!q.empty()) {
					auto now = q.front();
					q.pop();
					int x = now.F.F,y = now.F.S,lv = now.S;
					all[x][y] += lv;
					if((lv>>1) == 0) continue;
					
					if(1 < x && !vis[x-1][y] && keep[x-1][y] != '*') {
						vis[x-1][y] = true;
						q.push(mp(mp(x-1,y),(lv>>1)));
					}
					if(x < N && !vis[x+1][y] && keep[x+1][y] != '*') {
						vis[x+1][y] = true;
						q.push(mp(mp(x+1,y),(lv>>1)));
					}
					if(1 < y && !vis[x][y-1] && keep[x][y-1] != '*') {
						vis[x][y-1] = true;
						q.push(mp(mp(x,y-1),(lv>>1)));
					}
					if(y < M && !vis[x][y+1] && keep[x][y+1] != '*') {
						vis[x][y+1] = true;
						q.push(mp(mp(x,y+1),(lv>>1)));
					}
				}
			}
		}
	}
	
	int cnt=0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			//cout<<all[i][j]<<' ';
			if(all[i][j] > P) cnt++;
		}
		//cout<<'\n';
	}
	cout<<cnt;
	return 0;
}
