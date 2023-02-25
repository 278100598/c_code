#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		int x,y;
		x=a>b?a:b;
		y=a>b?b:a;
		while(x%y!=0)
		{
			a=x%y;
			x=y;
			y=a;
		}
		cout<<y<<endl;
	}
	return 0;
} 
