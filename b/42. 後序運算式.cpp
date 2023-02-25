#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int>s;
	string a;
	stringstream x,y;
	while(getline(cin,a))
	{
		x<<a;
		while(x>>a)
		{
			if(isdigit(a[0]))
			{
				int z;
				y<<a;
				y>>z;
				s.push(z);
				y.str("");
				y.clear();
				continue;
			}
			int j=s.top();
			s.pop();
			int i=s.top();
			s.pop();
			if(a=="+")
			{
				i+=j;
			}
			else if(a=="-")
			{
				i-=j;
			}
			else if(a=="*")
			{
				i*=j;
			}
			else if(a=="/")
			{
				i/=j;
			}
			else if(a=="%")
			{
				if(i>0&&j>0)
				{
					i%=j;
				}
				else if(i>0&&j<0)
				{
					i%=j;
					if(i!=0)
					{
						i+=j;
					}
				}
				else if(i<0&&j>0)
				{
					i%=j;
					if(i!=0)
					{
						i+=j;
					}
				}
				else if(i<0&&j<0)
				{
					i%=j;
				}
			}
			s.push(i);
		}
		cout<<s.top()<<endl;;
		x.str("");
		x.clear();
		s.pop();
	}
	return 0;
}
