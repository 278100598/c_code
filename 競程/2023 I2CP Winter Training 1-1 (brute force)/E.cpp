#include<iostream>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int ans=0;
pii mv[4]={{0,-1},{1,0},{0,1},{-1,0}};
string s;
bool vis[7][7];


bool check(int x,int y) {
	return (0<=x && x<7 && 0<=y && y<7 && !vis[x][y]);
}

void dfs(int x,int y,int index) {
	//cout<<x<<' '<<y<<' '<<index<<'\n';
	if(x==0&&y==6) {
		if(index==48) ans++;
		return;
	} else if(index==48) return;
	
	vis[x][y]=true;
	
	if(s[index]=='?') {
		for(int z=0;z<4;z++) {
			int xx=x+mv[z].ff,yy=y+mv[z].ss;
			if(!check(xx,yy)) continue;
			if(!check(xx+mv[z].ff,yy+mv[z].ss)) {
				if(check(xx+mv[(z+1)%4].ff,yy+mv[(z+1)%4].ss) && check(xx+mv[(z+3)%4].ff,yy+mv[(z+3)%4].ss)) continue;
			}
			dfs(xx,yy,index+1);
		}
	} else {
		int z;
		if(s[index]=='U') z=0;
		else if(s[index]=='R') z=1;
		else if(s[index]=='D') z=2;
		else if(s[index]=='L') z=3;
		int xx=x+mv[z].ff,yy=y+mv[z].ss;
		if(!check(xx,yy)) {
			vis[x][y]=false;
			return;
		}
		if(!check(xx+mv[z].ff,yy+mv[z].ss)) {
			if(check(xx+mv[(z+1)%4].ff,yy+mv[(z+1)%4].ss) && check(xx+mv[(z+3)%4].ff,yy+mv[(z+3)%4].ss)) {
				vis[x][y]=false;
				return;
			}
		}
		dfs(xx,yy,index+1);
	}
	
	vis[x][y]=false;
}

int main() {
	cin>>s;
	dfs(0,0,0);
	cout<<ans;
	
	return 0;
}
/*????????????????????????????????????????????????*/
