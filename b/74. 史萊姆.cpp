#include<iostream>
using namespace std;
int main()
{
	int n,t,a;
	cin>>n>>t;
	t/=n;
	n=1;
	n+=t;
	while(n!=1)
	{
		a++;
		n/=2;
	}
	cout<<a;
	return 0;
}
