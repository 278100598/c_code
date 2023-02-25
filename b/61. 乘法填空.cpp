#include<iostream>
using namespace std;
long long int change(string x)
{
	int t=0;
	for(int i=0;i<x.size();i++)
	{
		t*=10;
		t+=int(x[i]-48);
	}
	return t;
}
void go(string t,string f)
{
	if(f.empty())
	{
		int x,y;
		string a,b,c;
		x=t.find('x');
		y=t.find('=');
		a=t.substr(0,x);
		b=t.substr(x+1,y-x-1);
		c=t.substr(y+1);
		if(change(a)*change(b)==change(c))
		{
			cout<<t<<endl;
		}
		return;
	}
	int z=t.find('_');
	string ss;
	for(int i=0;i<f.size();i++)
	{
		ss=f;
		t[z]=f[i];
		ss.erase(i,1);
		go(t,ss);
	}
}
int main()
{
	int n,x,y;
	string a,b,c,g="",s;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		g+=char(i+48);
	}
	go(s,g);
	return 0;
}
