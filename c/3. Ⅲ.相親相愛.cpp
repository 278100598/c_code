#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int m,n;
	int mm=0,nn=0;
	cin>>m>>n;
	for(int i=1;i<=max(m,n);i++)
	{
		if(m%i==0)
		{
			mm+=i;
		}
		if(n%i==0)
		{
			nn+=i;
		}
	}
	if(mm==nn)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}
