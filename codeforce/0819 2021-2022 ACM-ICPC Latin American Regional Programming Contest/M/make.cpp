#include<iostream>
#include<time.h>
using namespace std;

int r(int min,int max) {
	int a = rand()%20000,b = rand()%10000, c=rand()%10;
	int d=a*100000+b*10+c;
	return d%(max-min+1)+min;
}

int main() {
	freopen("make.txt","w",stdout);
	
	srand(time(0));
	
	int N=6;
	cout<<N<<endl;
	while(N--) {
		int x=r(1,100);
		cout<<x<<" ";
		cout<<r(x*4,x*8)<<endl;
	}
	
	return 0;
}
