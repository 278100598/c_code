#include<iostream>
#include<queue> 
using namespace std;
int N,T,ans=0,x;
priority_queue<int> q;
int main() {
	cin>>N>>T;
	for(int i=1;i<=N;i++) {
		cin>>x;
		if(T <= i) continue;
		while(!q.empty() && i+q.top() > T-1) q.pop();
		if(x <= T-1) q.push(x-i);
		
		ans = max(ans,(int)q.size());
	}
	cout<<ans;
	return 0;
}
