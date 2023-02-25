#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream a,b;
	a.open("grand.out",ios::in);
	b.open("GGG.out",ios::in);
	int h1,t1,h2,t2;
	for(int count=0;a>>h1,b>>h2;count++) {
		if((h1==-1)^(h2==-1)) cout<<count<<endl;
		if(h1==-1&&h2==-1) continue;
		a>>t1; b>>t2;
		int n,x;
		for(int i=0;i<3;i++) {
			a>>n;
			for(int j=0;j<n;j++) a>>x;
		}
		for(int i=0;i<3;i++) {
			b>>n;
			for(int j=0;j<n;j++) b>>x;
		}
	}
}
