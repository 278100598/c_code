#include<iostream>
using namespace std;
int N,arr[100000],ltor[100000],rtol[100000];
int main() {
	cin>>N;
	for(int i=0;i<N;i++) cin>>arr[i];
	
	int pre=0;
	for(int i=0;i<N;i++) {
		pre = max(pre + 1,arr[i]);
		ltor[i] = pre;
	}
	pre=-1;
	for(int i=N-1;i>=0;i--) {
		pre = max(pre + 1,arr[i]);
		rtol[i] = pre;
	}
	
	long long int ans=0;
	pre=-1;
	for(int i=0;i<N;i++) {
		int now = min(ltor[i],rtol[i]);
		if(now == pre) ans+=1;
		
		ans += (now - arr[i]);
		pre = now;
	}
	cout<<ans;
	return 0;
}
