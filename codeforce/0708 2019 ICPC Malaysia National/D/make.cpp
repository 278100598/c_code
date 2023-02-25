#include<iostream>
#include<time.h>
using namespace std;

int r(int min,int max) {
	int a = rand()%10000,b = rand()%10000;
	int c=a*10000+b;
	return c%(max-min+1)+min;
}

int main() {
	freopen("make.txt","w",stdout);
	
	srand(time(0));
	
	int N=r(1,20000),M=r(1,20000);
	cout<<N<<" "<<M<<endl;
	while(M--) {
		cout<<(r(0,1)?"a":"b")<<" ";
		cout<<r(1,N)<<" ";
		cout<<r(1,N)<<" ";
		cout<<r(1,1000000)<<endl;
	}
	
	return 0;
}
