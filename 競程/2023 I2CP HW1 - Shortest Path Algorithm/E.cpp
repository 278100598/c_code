#include<iostream>
using namespace std;
long long int sum=0,N,K,d[301][301];


int main() {
	cin>>N;
	
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>d[i][j];
		}
	}
	
	cin>>K;
	while(K--) {
		long long int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c);
		d[b][a]=min(d[b][a],c);
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				d[i][j]=min(d[i][j],d[i][a]+d[a][b]+d[b][j]);
				d[i][j]=min(d[i][j],d[i][b]+d[b][a]+d[a][j]);
			}
		}
		
		long long int sum=0;
		for(int i=1;i<=N;i++) {
			for(int j=1;j<i;j++) sum+=d[i][j];
		}
		
		cout<<sum<<' ';
	}
	
	return 0;
}
