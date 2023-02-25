#include<iostream>
#include <math.h>
#include<map>
using namespace std;
int pm(long long int a,int p,int m) {
	long long int out=1;
	while(p>0) {
		if(p%2==1) {
			out = (out*a)%m;
		}
		p /= 2;
		a = (a*a)%m;
	}
	return out;
}
map<int,int>x;
//3 888307073 355365569 170620974
int main() {
	int g=3,p=888307073,a=355365569,b=170620974,m;
	long long int f,t;
	cin>>g>>p>>a>>b;
	m=ceil(sqrt(p));
	t=1;
	for(int i=0;i<m;i++) {
		x[t]=i;
		t = (t*g)%p;
	}
	f=pm(g,p-1-m,p);
	t=a;
	for(int i=0;i<m;i++) {
		auto it = x.find(t);
		if(it!=x.end()) {
			cout<<pm(b,i*m+it->second,p)<<endl;
		}
		t=(t*f)%p;
	}
	return 0;
}
