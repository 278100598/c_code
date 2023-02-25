#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,m,n;
	cin>>h>>m>>n;
	if(m>=h)
	{
		cout<<1;
	}
	else if(n>=m)
	{
		cout<<"lose";
	}
	else
	{
		if((h-m)%(m-n)==0)
		{
			cout<<(h-m)/(m-n)+1;
		}
		else
		{
			cout<<(h-m)/(m-n)+2;
		}
	}
	return 0;
} 
