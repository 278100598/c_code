#include<iostream>
#include<vector>
#include<stack>
using namespace std;

long long int getRemod(long long int a,long long int b);

int main() {
	long long int n,p,k;
	cin>>n>>p;
	
	for(int i=0;i<n;i++) {
		cin>>k;
		cout<<getRemod(k,p)<<endl;
	}
	return 0;
} 

long long int getRemod(long long int a,long long int b) {
	long long int x,y,xx,yy,aa=a,bb=b;
	bool bo = false;
	if(a>b){
		xx=1;
		yy=0;
		x=0;
		y=1;
	}
	else{
		xx=0;
		yy=1;
		x=1;
		y=0;
	}
	while(a!=1 && b!=1) {
		long long int tmp,q;
		if(a>b){
			q=a/b;
			a=a%b;
		}
		else{
			q=b/a;
			b=b%a;
		}
		tmp=x;
		x = xx-x*q;
		xx=tmp;
		tmp=y;
		y = yy-y*q;
		yy=tmp;
		if(a==0||b==0) {
			bo=true;
			break;
		}
	}
	if(bo) x=-1;
	return x;
}
