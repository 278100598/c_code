#include<iostream>
using namespace std;
int main()
{
	int n,y;
	cin>>n>>y;
	int a,b,*x=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a;
		x[i]=a;
	}
	a=0;
	b=n-1;
	while(x[a]+x[b]!=y)
	{
		if(a==b)
		{
			break;
		}
		if(x[a]+x[b]>y)
		{
			b--;
		}
		else if(x[a]+x[b]<y)
		{
			a++;
		}
	}
	if(a!=b)
	{
		cout<<a<<" "<<b;
	}
	else
	{
		cout<<"IMPOSSIBLE";
	}
	return 0;
}
