#include<iostream>
using namespace std;
long long int d[10000],K,N;


int main() {
	cin>>N>>K;
	
	int ans=0;
	for(int X=2;X<N;X++) {
		
		for(int i=1;i<=N;i++) d[i]=0;
		
		d[1]=1;
		for(int i=1;i<N;i++) {
			if(d[i] > K) {
				d[N]=-1;
				break;
			}
			d[i+1] += d[i];
			if(i+X <= N) d[i+X] += d[i];
			if(i*7 <= N) d[i*7] += d[i];
			
			/*cout<<i<<"X"<<endl;
			for(int j=0;j<=N;j++) cout<<j<<" "<<d[j]<<endl;
			cout<<endl;*/
		}
		//cout<<d[N]<<endl;
		if(d[N] == K) {
			ans = X;
			break;
		}
	}
	
	cout<<ans;
	return 0;
}
/*
3 1
*/
