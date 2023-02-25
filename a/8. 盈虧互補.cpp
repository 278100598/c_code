#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	while(cin>>a&&a!=0)
	{
		int b=0,c=0;
		for(int i=1;i<a;i++)
		{
			if(a%i==0)
			{
				b+=i;
			}
		}
		if(a==b)
		{
			cout<<"="<<a<<"\n";
		} 
		else
		{
			for(int i=1;i<b;i++)
			{
				if(b%i==0)
				{
					c+=i;
				}
			}
			if(c==a)
			{
				cout<<b<<"\n";
			}
			else
			{
				cout<<0<<"\n";
			}
		}
	}
	return 0;
}
