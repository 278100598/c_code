#include<iostream>
#include<bitset>
using namespace std;
int N,love[1000001],sum=0;
bool vis[1000001];
void dfs(int now) {
	if(vis[now] || now==love[now]) return;
	
	int a=love[now],b=love[a],c=love[b];
	//cout<<now<<" "<<a<<" "<<b<<endl;
	if(now==c) {
		vis[now]=true;
		vis[a]=true;
		vis[b]=true;
		sum++;
	}
}
int main() {
	cin>>N;
	for(int i=1;i<=N;i++) cin>>love[i];
	for(int i=1;i<=N;i++) dfs(i);
	cout<<sum;
	
	return 0;
}
