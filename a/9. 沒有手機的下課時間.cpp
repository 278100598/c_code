#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	while(cin>>x)
	{
		int x1,x2,x3,x4,y,c;
		x1=x/1000;
		x2=(x/100)%10;
		x3=(x/10)%10;
		x4=x%10;
		cin>>y;
		for(int i=0;i<y;i++)
		{
			cin>>c;
			int c1,c2,c3,c4,a=0,b=0;
			c1=c/1000;
			c2=(c/100)%10;
			c3=(c/10)%10;
			c4=c%10;
			if(c1==x1)
			{
				a++;
			}
			if(c1==x2)
			{
				b++;
			}
			if(c1==x3)
			{
				b++;
			}
			if(c1==x4)
			{
				b++;
			}
			if(c2==x2)
			{
				a++;
			}
			if(c2==x1)
			{
				b++;
			}
			if(c2==x3)
			{
				b++;
			}
			if(c2==x4)
			{
				b++;
			}
			if(c3==x3)
			{
				a++;
			}
			if(c3==x1)
			{
				b++;
			}
			if(c3==x2)
			{
				b++;
			}
			if(c3==x4)
			{
				b++;
			}
			if(c4==x4)
			{
				a++;
			}
			if(c4==x1)
			{
				b++;
			}
			if(c4==x2)
			{
				b++;
			}
			if(c4==x3)
			{
				b++;
			}
			cout<<a<<"A"<<b<<"B"<<"\n";
		} 
		
	}
	return 0;
}
