#include<iostream>
#include<bitset>
using namespace std;
int T,N,sum;
bitset<45001> w[101];

int main() {
	cin>>T;
	while(T--) {
		cin>>N;
		for(int i=1;i<=N;i++) w[i]=0;
		w[0]=1;
		sum=0;
		for(int i=0;i<N;i++) {
			int x;
			cin>>x;
			sum += x;
			for(int j=i;j>=0;j--) {
				w[j+1] |= (w[j]<<x);
			}
		}
		
		int ans=-1e9;
		for(int i=0;i<=sum;i++) {
			if(w[N/2][i] && abs((sum-i)-i) < abs((sum-ans)-ans)) {
				ans = i;
			}
		}
		cout<<min(sum-ans,ans)<<' '<<max(sum-ans,ans)<<'\n';
		if(T!=0) cout<<'\n';
	}
	
	return 0;
}
