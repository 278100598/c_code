#include<iostream>
using namespace std;
int t[4][4];

void ro(int x) {
	while(x--) {
		int tmp[4][4];
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) tmp[i][j]=t[3-j][i];
		}
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) t[i][j]=tmp[i][j];
		}
	}
}

void go() {
	bool vis[4][4];
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) vis[i][j]=false;
	}
	
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			int x=i,y=j;
			while(y!=0 && t[x][y-1]==0) {
				t[x][y-1]=t[x][y];
				t[x][y]=0;
				y--;
			}
			if(y!=0 && t[x][y-1]==t[x][y] && !vis[x][y-1]) {
				t[x][y-1] *= 2;
				t[x][y] = 0;
				vis[x][y-1] = true;
			}
		}
	}
	
}

int main() {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) cin>>t[i][j];
	}
	
	int x;
	cin>>x;
	if(x==0) {
		go();
	} else if(x==1) {
		ro(3);
		go();
		ro(1);
	} else if(x==2) {
		ro(2);
		go();
		ro(2);
	} else if(x==3) {
		ro(1);
		go();
		ro(3);
	}
	
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) cout<<t[i][j]<<' ';
		cout<<'\n';
	}
	
	return 0;
}
