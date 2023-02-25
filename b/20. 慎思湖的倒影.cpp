#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,i=1;
	bool x=0;
	cin>>a;
	while(i>0)
	{
		for(int j=0;j<i;j++)
		{
			cout<<"*";
		}
		cout<<endl;
		if(i==a)
		{
			for(int j=0;j<i;j++)
			{
				cout<<"*";
			}
			cout<<endl;
			x=1;
		}
		if(x)
		{
			i--;
		}
		else
		{
			i++;
		}
	}
	return 0;
} 
