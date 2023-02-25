#include<iostream>
#include<set>
using namespace std;
int main() {
	int n,m,mod=1000000007;
	cin>>n>>m;
	int *x=new int[n+1];
	set<int>s;
	for(int i=0;i<m;i++) {
		int z;
		cin>>z;
		s.insert(z);
	}
	x[0]=1;
	for(int i=1;i<n;i++) {
		x[i]=0;
	}
	long long int sum=0;
	for(int i=1;i<=n;i++) {
		sum+=x[i-1];
		for(auto it=s.begin();it!=s.end();it++) {
			if(*it<=i) {
				sum-=x[i-*it];
				if(*it<i) {
					sum+=x[i-*it-1];
				}
			}
		}
		x[i]=(sum%mod);
		/*
		for(int j=0;j<=n;j++) {
			cout<<j<<" "<<x[j]<<endl;
		}
		cout<<endl;
		*/
	}
	cout<<x[n];
} 
