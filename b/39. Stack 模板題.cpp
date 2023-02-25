#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	int b,x,j=-1;
	cin>>x;
	int c[x];
	for(int i=0;i<x;i++)
	{
		cin>>a;
		if(a=="PUSH")
		{
			cin>>b;
			j++;
			c[j]=b;
		}
		if(a=="POP")
		{
			if(j!=-1)
			{
				cout<<c[j]<<endl;
				j--;
			}
		}
	}
	return 0;
}
