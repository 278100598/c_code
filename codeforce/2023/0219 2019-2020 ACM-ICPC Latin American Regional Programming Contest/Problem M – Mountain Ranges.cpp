#include<bits/stdc++.h>
using namespace std;
int N,X,arr[1005];

int main() {
	cin>>N>>X;
	for(int i=0;i<N;i++) cin>>arr[i];
	
	int cnt=1,ans=1;
	for(int i=1;i<N;i++) {
		if(arr[i]-arr[i-1] > X) cnt=1;
		else cnt++;
		ans = max(ans,cnt);
	}
	
	cout<<ans;
	return 0;
}
