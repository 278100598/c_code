#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<string>a,b;
	string c;
	while(getline(cin,c))
	{
		if(c=="0")
		{
			break;
		}
		else
		{
			a.insert(c);
		}
	}
	while(getline(cin,c))
	{
		if(c=="0")
		{
			break;
		}
		else
		{
			b.insert(c);
		}
	}
	if(a.size()==b.size())
	{
		cout<<"Equal";
	}
	else if(a.size()>b.size())
	{
		cout<<"A";
	}
	else if(a.size()<b.size())
	{
		cout<<"B";
	}
	return 0;
} 
