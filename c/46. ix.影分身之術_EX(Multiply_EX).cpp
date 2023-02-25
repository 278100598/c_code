#include<iostream>
#include<map>
using namespace std;
int main() {
	long long int n,x,y,z=0;
	cin>>n>>x>>y;
	if(n>0)z=1;
	while(n>1) {
		z*=3;
		n--;
	}
	bool yes=true;
	while(yes&&z>0) {
		if((x<z||z*2<=x)&&(y<z||z*2<=y)) {
			yes=false;
		} else {
			x%=z;
			y%=z;
		}
		z/=3;
	}
	cout<<(yes?"Hit":"Miss");
	return 0;
}
