#include<iostream>
using namespace std;
int N;
bool vis[200001];
int main() {
	cin>>N;
	
	for(int i=0;i<N-1;i++) {
		int x;
		cin>>x;
		vis[x]=true;
	}
	
	for(int i=1;i<=N;i++) {
		if(!vis[i]) {
			cout<<i;
			break;
		}
	}
	
	return 0;
}
