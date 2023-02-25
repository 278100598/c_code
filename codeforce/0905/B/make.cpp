#include<iostream>
#include<time.h>
using namespace std;

int r(int min,int max) {
	int a = rand()%10000,b = rand()%10000,c = rand()%10;
	int d=a*100000+b*10+c;
	return d%(max-min+1)+min;
}
long long int llr(long long int min,long long int max) {
	long long int a=r(0,1e9-1),b=r(0,1e9-1);
	long long int c=a*1e9+b;
	return c%(max-min+1)+min;
}
long long int T,W,X,Y,D;

int main() {
	srand(time(0));
	
	T=llr(1,1e15);
	W=llr(T,1e15);
	Y=llr(1,1e9);
	X=llr(1,6*Y-1);
	D=r(1,6);
	cout<<W<<" "<<X<<" "<<Y<<" "<<T<<" "<<D<<endl;
	
	return 0;
}
