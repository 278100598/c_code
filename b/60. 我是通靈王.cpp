#include<iostream>
using namespace std;
int a,b,c,d,e,f,x[5],t;
bool go(int n,string s)
{
	if(s.size()==0)
	{
		if(f==n)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int m;
	if(s.size()==4)
	{
		m=a;
	}
	else if(s.size()==3)
	{
		m=b;
	}
	else if(s.size()==2)
	{
		m=d;
	}
	else if(s.size()==1)
	{
		m=e;
	}
	string ss;
	for(int i=0;i<s.size();i++)
	{
		ss=s;
		ss.erase(i,1);
		if(go(n+x[int(s[i])-48]*m,ss))
		{
			return true;
		}
	}
	return false;
} 
int main()
{
	
	string s="01234",ss;
	bool answer[5];
	cin>>a>>b>>c>>d>>e>>f;
	cin>>x[0]>>x[1]>>x[2]>>x[3]>>x[4];
	for(int i=0;i<5;i++)
	{
		ss=s;
		ss.erase(i,1);
		if(go(c*x[i],ss))
		{
			answer[i]=true;
		}
		else
		{
			answer[i]=false;
		}
	}
	for(int i=0;i<5;i++)
	{
		if(answer[i])
		{
			cout<<char(i+65);
		}
	}
	return 0;
}
