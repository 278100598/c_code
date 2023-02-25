#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int M,N,t;
	cin>>M;
	for(int time=1;time<=M;time++) {
		cin>>N;
		long long int x[N];
		for(int i=0;i<N;i++) cin>>x[i];
		sort(x,x+N);
		
		long long int total=0,t=0;
		for(int i=0;i<N;i++) {
			if(t+x[i]<=x[i]*2) {
				total++;
				t+=x[i];
			}
		}
		cout<<"Case #"<<time<<": "<<total<<endl;
	}
	return 0;
}
