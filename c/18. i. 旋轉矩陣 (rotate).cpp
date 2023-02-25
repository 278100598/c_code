#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int x=a,y=b;
	while(x%y)
	{
		int t=x;
		x=y;
		y=t%y;
	}
	cout<<b/y;
	return 0;
}
