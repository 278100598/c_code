#include<iostream>
#include <bitset>
using namespace std;
int d[2005][1024];
bool no[2005][2005];
int main()
{
	int n,e,k,MOD=1000000007;
	cin>>n>>e>>k;
	for(int i=0;i<=n+1;i++) {
		for(int j=0;j<=n;j++) no[i][j]=false;
		for(int j=0;j<(1<<(e*2+1));j++) d[i][j]=0;
	}
	for(int i=0;i<k;i++) {
		int a,b;
		cin>>a>>b;
		no[a][b]=true;
	}
	d[0][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<(1<<(e*2+1));j++) {
			for(int k=-e;k<=e;k++) {
				int x=i+k;
				if(x<1||n<x||no[i][x]||((j<<1)&((1<<(e*2+1))-2)) & (1<<(e-k))) continue;
				
				//bitset<5> a((j<<1)&((1<<(e*2+1))-2)),b(j>>1),c(j);
				//cout<<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<endl;
				
				x=((j<<1)&((1<<(e*2+1))-2)) | (1<<(e-k));
				d[i][x]=(d[i][x]+d[i-1][j]) % MOD;
				//cout<<i<<" "<<x<<" "<<d[i][x]<<endl;
			}
		}
	}
	//((j<<1)and((1<<(e*2+1))-1))
	long long int sum=0;
	for(int i=0;i<(1<<(e*2+1));i++) {
		sum+=d[n][i];
		bitset<9> x(i);
		cout<<x<<" "<<d[n][i]<<endl;
	}
	cout<<sum%MOD;
    return 0;
}
