#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,sum;
	cin>>x>>y;
	sum=x+y;	
	sum+=y/3;
	x+=y/3;
	while(x>=5)
	{
		sum+=x/5;
		x=x/5+x%5;
	}
	cout<<sum;
	return 0;
} 
