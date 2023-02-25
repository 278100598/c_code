#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	string a;
	int z=1;
	bool one=false,first=true;
	while(cin>>a)
	{
		if(first&&a.size()>1000)
		{
			first=false;
			one=true;
		}
		if(z==10&&one)
		{
			break;
		}
		list<char>x;
		list<char>::iterator i=x.end();
		for(int index=0;index<a.size();index++)
		{
			if(a[index]=='[')
			{
				i=x.begin();
			}
			else if(a[index]==']')
			{
				i=x.end();
			}
			else if(a[index]=='-')
			{
				if(i!=x.begin())
				{
					i--;
					x.erase(i--);
					i++;
				}
			}
			else if(a[index]=='|')
			{
				if(i!=x.end())
				{
					x.erase(i++);
				}
			}
			else
			{
				x.insert(i,a[index]);
			}
		}
		a="";
		for(list<char>::iterator j=x.begin();j!=x.end();j++)
		{
			a+=*j;
		}
		cout<<a<<'\n';
		z++;
	}
	return 0;
}
