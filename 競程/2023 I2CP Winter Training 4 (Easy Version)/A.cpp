#include<iostream>
#include<queue>
using namespace std;
int L,dis[2000000];
string s;
bool vis[2000000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>L) {
		if(L==0) break;
		cin>>s;
		
		queue<int> q;
		for(int i=0;i<s.size();i++) {
			if(s[i]=='R' || s[i]=='Z') {
				q.push(i);
				vis[i]=true;
			} else {
				vis[i]=false;
			}
			dis[i]=0;
		}
		
		int ans=-1;
		while(ans == -1) {
			int x=q.front();
			q.pop();
			
			if(x!=0&&!vis[x-1]) {
				vis[x-1]=true;
				q.push(x-1);
				dis[x-1]=dis[x]+1;
			}
			if(x!=L-1&&!vis[x+1]) {
				vis[x+1]=true;
				q.push(x+1);
				dis[x+1]=dis[x]+1;
			}
			if(s[x]=='D' || s[x]=='Z') ans=dis[x];
		} 
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
