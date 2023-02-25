#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    long long int a,b,c,x=0;
	for(int i=0;i<5;i++)
	{
		cin>>a>>b>>c;
		if(a>b&&a>c)
		{
			if(a<b+c)
			{
				x++;
			}
		}
		else
		{
			if(max(b,c)<min(b,c)+a)
			{
				x++;
			}
		}
	}
	cout<<x;
	return 0;
}
