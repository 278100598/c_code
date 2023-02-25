#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int a;
	cin>>a;
	bool* x = new bool[a];
	x[2]=true;
	for(int i=3;i<a;i+=2)
	{
		x[i]=true;
	}
	for(int i=2;i*i<a;i++)
	{
		if(x[i])
		{
			for(int j=i*i;j<a;j+=2*i)
			{	
				x[j]=false;
			}
		}
	}
	if(a!=2)
	{
		cout<<2;
	}
	for(int i=3;i<a;i+=2)
	{
		if(x[i])
		{
			cout<<" "<<i;
		}
	}
	return 0;
} 
