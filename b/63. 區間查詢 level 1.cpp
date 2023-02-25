#include<iostream>
#include<algorithm>
using namespace std;
int *x,n,q,rr;
int find(int l,int r,int t)
{
	if(l==r)
	{
		return l;
	}
	int m=(l+r)/2;
	if(x[m]==t)
	{
		return m;
	}
	else if(x[m]<t)
	{
		return find(m+1,r,t);
	}
	else
	{
		return find(l,m,t);
	}
}
int main()
{
	cin>>n;
	x=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	sort(x,x+n);
	cin>>q;
	int a,b,c,d;
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		c=find(0,n-1,a);
		while(c!=0&&x[c-1]==a)
		{
			c=find(0,c-1,a);
		}
		d=find(0,n-1,b);
		while(d!=n-1&&x[d+1]==b)
		{
			d=find(d+1,n-1,b);
		}
		if(x[c]<a)
		{
			c++;
		}
		if(b<x[d])
		{
			d--;
		}
		cout<<d-c+1<<endl;
	}
	return 0;
}
