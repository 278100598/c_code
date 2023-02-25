#include<iostream>
using namespace std;
int mn=17;
int m[8][8];
void dfs(int x,int y,int num) {
	if(num>mn)return;
	if(x==0&&y==0) {
		bool tmp[8][8];
		for(int i=1;i<=6;i++) {
			for(int j=1;j<=6;j++) {
				tmp[i][j]=(m[i][j]==1);
			}
		}
		for(int i=1;i<=6;i++) {
			if(m[0][i]==2) {
				for(int j=1;j<=6;j++) {
					if(m[j][i]==1) break;
					else tmp[j][i]=true;
				} 
			}
		}
		for(int i=1;i<=6;i++) {
			if(m[7][i]==2) {
				for(int j=6;j>=0;j--) {
					if(m[j][i]==1) break;
					else tmp[j][i]=true;
				} 
			}
		}
		for(int i=1;i<=6;i++) {
			if(m[i][0]==2) {
				for(int j=1;j<=6;j++) {
					if(m[i][j]==1) break;
					else tmp[i][j]=true;
				}
			}
		}
		for(int i=1;i<=6;i++) {
			if(m[i][7]==2) {
				for(int j=6;j>=0;j--) {
					if(m[i][j]==1) break;
					else tmp[i][j]=true;
				}
			}
		}
		bool yes = true;
		for(int i=1;i<=6&&yes;i++) {
			for(int j=1;j<=6&&yes;j++) {
				if(!tmp[i][j]) yes = false;
			}
		}
		if(yes) mn=min(mn,num);
		return;
	}
	
	int xx=x,yy=y,xt=x,yt=y;
	if(x==0) {
		if(y==6) {
			xx=1;
			yy=7;
		}
		else yy=y+1;
		xt=1;
	} else if(x==7){
		if(y==1) {
			xx=6;
			yy=0;
		}
		else yy=y-1;
		xt=6;
	} else if(y==0){
		if(x==1) {
			xx=0;
			yy=0;
		}
		else xx=x-1;
		yt=1;
	} else if(y==7){
		if(x==6) {
			xx=7;
			yy=6;
		}
		else xx=x+1;
		yt=6;
	}
	
	
	bool a=false,b=false,c=false,d=false;
	for(int i=1;i<=xt;i++) {
		if(m[yt][i]==1)break;
		if(i==xt&&x!=0)a=true;
	}
	for(int i=6;i>=xt;i--) {
		if(m[yt][i]==1)break;
		if(i==xt&&x!=7)b=true;
	}
	for(int i=1;i<=yt;i++) {
		if(m[i][xt]==1)break;
		if(i==yt&&y!=0)c=true;
	}
	for(int i=6;i>=yt;i--) {
		if(m[i][xt]==1)break;
		if(i==yt&&y!=7)d=true;
	}
	
	if(m[yt][xt]==0) {
		m[y][x]=2;
		dfs(xx,yy,num+1);
		m[y][x]=0;
	}
	dfs(xx,yy,num);
}
int main() {
	char c;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			cin>>c;
			if(c=='#') m[j][i]=1;
			else m[j][i]=0;
		}
	}
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			if(m[i][j]!=1) {
				bool t=true;
				for(int k=j;k<=7&&t;k++) {
					if(k==7)t=false;
					if(m[i][k]==1) break;
				}
				for(int k=j;k>=0&&t;k--) {
					if(k==0)t=false;
					if(m[i][k]==1) break;
				}
				for(int k=i;k<=7&&t;k++) {
					if(k==7)t=false;
					if(m[k][j]==1) break;
				}
				for(int k=i;k<=7&&t;k--) {
					if(k==0)t=false;
					if(m[k][j]==1) break;
				}
				if(t)mn=-1;
			}
			
		}
	}
	
	dfs(0,1,0);
	cout<<mn;
	return 0;
}
