#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<char>x,y;
	char a;
	while(cin>>a&&a!='*')
	{
		if(48<=a&&a<=57)
		{
			x.push_back(a);
		}
		else
		{
			y.push_back(a);
		}
	}
	if(x.size()>=y.size())
	{
		for(int i=0;i<x.size();i++)
		{
			cout<<x[i]<<" ";
		}
	}
	else
	{
		for(int i=0;i<y.size();i++)
		{
			cout<<y[i]<<" ";
		}
	}
	return 0;
}
