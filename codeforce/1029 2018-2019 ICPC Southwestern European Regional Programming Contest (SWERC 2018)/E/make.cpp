#include<iostream>
#include<time.h>
using namespace std;
int N=10,sum=97;

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

int main() {
	srand(time(0));
	freopen("make.txt","w",stdout);
	
	cout<<N<<'\n';
	for(int i=1;i<=N-1;i++) {
		int x=r(0,sum);
		sum-=x;
		cout<<to_string(r(0,1))<<' '<<x<<'\n';
	}
	cout<<to_string(r(0,1))<<' '<<sum<<'\n';
	
	return 0;
}

