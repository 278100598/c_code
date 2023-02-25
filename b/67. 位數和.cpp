#include<iostream>
using namespace std;
int main()
{
	int n,a;
	cin>>n;
	while(n>9)
	{
		a=n;
		n=0;
		while(a>0)
		{
			n+=a%10;
			a/=10;
		}
	}
	cout<<n;
	return 0;
}
