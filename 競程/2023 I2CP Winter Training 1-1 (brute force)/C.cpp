#include<iostream>
using namespace std;
int q[8],ans,turn=1,tmp[8];

void go(int x,int cnt) {
	if(x==8) {
		ans=min(ans,cnt);
		return;
	}
	
	for(int i=0;i<8;i++) {
		bool ok=true;
		for(int j=0;j<x;j++) {
			if(tmp[j]==i || abs(i-tmp[j])==x-j) {
				ok=false;
				break;
			}
		}
		
		if(ok) {
			tmp[x]=i;
			if(q[x]==i) go(x+1,cnt);
			else go(x+1,cnt+1);
		}
	}
}

int main() {
	while(cin>>q[0]) {
		q[0]--;
		for(int i=1;i<8;i++) {
			cin>>q[i];
			q[i]--;
		}
		
		ans=1e9;
		go(0,0);
		
		printf("Case %d: %d\n",turn++,ans);
	}
	
	return 0;
}
