#include<iostream>
using namespace std;
int lx,rx,lc,rc;
bool r=false;
void go(string s)
{
	int x=0;
	bool xx=false,nega=false;
	if(s[s.size()-1]=='x')
	{
		xx=true;
		s.erase(s.size()-1);
	}
	if(s[0]=='+')
	{
		s.erase(0,1);
	}
	if(s[0]=='-')
	{
		s.erase(0,1);
		nega=true;
	}
	for(int i=0;i<s.size();i++)
	{
		x*=10;
		x+=(int(s[i])-48);
	}
	if(s.empty())
	{
		x=1;
	}
	if(nega)
	{
		x*=-1;
	}
	if(xx)
	{
		((r)?rx:lx)+=x; 
	}
	else
	{
		((r)?rc:lc)+=x; 
	}
}
int main()
{
	string s,t;
	cin>>s;
	t=s[0];
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='+')
		{
			go(t);
			t="";
		}
		else if(s[i]=='-')
		{
			go(t);
			t="";
		} 
		if(s[i]=='=')
		{
			go(t);
			t=s[i+1];
			i++;
			r=true;
		}
		else
		{
			t+=s[i];
		}
	}
	go(t);
	if(lx==rx&&lc==rc)
	{
		cout<<"Infinite solutions";
	}
	else if(lx==rx)
	{
		cout<<"No solution";
	}
	else if(lc==rc)
	{
		cout<<"x=0";
	}
	else
	{
		cout<<"x="<<((rc-lc)/(lx-rx));
	}
	//cout<<endl<<lx<<" "<<rx<<" "<<lc<<" "<<rc;
	return 0;
}
