#include<iostream>
using namespace std;
int main() {
	long long int n,x,y,z,mod=1000000007;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>x>>y>>z;
		long long int s=y;
		y=1;
		while(z>0) {
			if(z%2==1) {
				y=(y*s)%(mod-1);
			}
			z/=2;
			s=(s*s)%(mod-1);
		}
		s=x;
		x=1;
		while(y>0) {
			if(y%2==1) {
				x=(x*s)%mod;
			}
			y/=2;
			s=(s*s)%mod;
		}
		cout<<x<<endl;
	}
	return 0;
}
