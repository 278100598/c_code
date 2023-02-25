#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c,w,x,a=0; 
	while(cin>>c>>w)
	{
		while(c>=12||w>=12)
		{
			x=c/12;
			c=c%12;
			if(w>=x)
			{
				w=w-x;
				a+=x;
				c+=2*x;
			}
			if(12-c<w)
			{
				w=w+c-12;
				c=12;
			}
		}
		cout<<a<<"\n";
	}
	return 0;
}
