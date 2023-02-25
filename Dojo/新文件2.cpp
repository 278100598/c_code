#include<iostream>
using namespace std;
int main()
{
	unsigned long long int x,a=0;
	cin>>x;
	a+=(x/50);
	x%=50;
	a+=(x/10);
	x%=10;
	a+=(x/5);
	
	x%=5;
	a+=x;
	cout<<a;
	return 0;
}
