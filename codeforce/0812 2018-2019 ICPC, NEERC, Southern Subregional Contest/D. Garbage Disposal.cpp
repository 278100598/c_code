#include<iostream>
using namespace std;
int N,K;
int main() {
	cin>>N>>K;
	int a=0,b=0;
	long long int ans=0;
	for(int i=0;i<N;i++) {
		cin>>b;
		if(a+b >= K) {
			ans += (a+b)/K;
			a = (a+b)%K;
		} else {
			if(a > 0) {
				ans++;
				a = 0;
			} else {
				a = b;
			}
		}
	}
	if(a > 0) ans++;
	cout<<ans;
	return 0;
}
