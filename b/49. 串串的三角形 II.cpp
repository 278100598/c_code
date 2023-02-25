#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	long long int b,c,d,x[3]={},j=0,s;
	cin>>b>>c>>d;
	for(long long int i=1;i<=100;i++)
	{
		if(i*(i*i-b*i+c)==d)
		{
			x[j]=i;
			j++;
		}
		if(j==3)
		{
			break;
		}
	}
	if(x[1]==0&&x[2]==0)
	{
		x[1]=x[0];
		x[2]=x[0];
	}
	else if(x[2]==0)
	{
		x[2]=b-x[0]-x[1];
	}
	s=x[0]+x[1]+x[2];
	cout<<(s*(s-x[0]*2)*(s-x[1]*2)*(s-x[2]*2))/16; 
	return 0;
} 
