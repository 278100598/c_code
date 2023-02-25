#include<iostream>
using namespace std;
int N;
int main() {
	cin>>N;
	int sum=0,mx=-1;
	for(int i=0;i<N;i++) {
		int k;
		cin>>k;
		mx = max(mx,k);
		sum += k;
	}
	if(N==1 || N==2) cout<<0;
	else if(mx <= (sum-mx)*2) cout<<(sum/3);
	else cout<<(sum-mx);
	
	return 0;
}
