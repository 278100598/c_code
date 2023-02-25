#include<iostream>
using namespace std;
int main() {
	long long int a[3],b[3],n;
	for(int i=0;i<3;i++) {
		a[i]=0;
		b[i]=0;
	}
	cin>>n;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		a[i%3]+=x;
	}
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		b[i%3]+=x;
	}
	
	cout<<(a[0]*b[0]+a[1]*b[2]+a[2]*b[1])<<" ";
	cout<<(a[2]*b[2]+a[0]*b[1]+a[1]*b[0])<<" ";
	cout<<(a[1]*b[1]+a[0]*b[2]+a[2]*b[0]);
	return 0;
}
