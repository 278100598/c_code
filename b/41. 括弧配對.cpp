#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char>b;
	string a;
	while(cin>>a)
	{
		bool yn=true;
		for(int i=0;i<a.length();i++)
		{
			char x=a[i];
			if(x=='<')
			{
				b.push('<');
			}
			else if(x=='{')
			{
				b.push('{');
			}
			else if(x=='[')
			{
				b.push('[');
			}
			else if(x=='(')
			{
				b.push('(');
			}
			if(x=='>')
			{
				if(b.empty()||b.top()!='<')
				{
					yn=false;
					break;
				}
				else
				{
					b.pop();
				}
			}
			if(x=='}')
			{
				if(b.empty()||b.top()!='{')
				{
					yn=false;
					break;
				}
				else
				{
					b.pop();
				}
			}
			if(x==']')
			{
				if(b.empty()||b.top()!='[')
				{
					yn=false;
					break;
				}
				else
				{
					b.pop();
				}
			}
			if(x==')')
			{
				if(b.empty()||b.top()!='(')
				{
					yn=false;
					break;
				}
				else
				{
					b.pop();
				}
			}
		}
		if(yn)
		{
			cout<<'T'<<endl;
		}
		else
		{
			cout<<'F'<<endl;
		}
	}
	return 0;
}
