#include<bits/stdc++.h>
#include <vector>
using namespace std;
int maximun[250000],minimun[250000],inin[60000];
void build(int l,int r,int i)
{
	if(l==r)
	{
		maximun[i]=inin[l];
		minimun[i]=inin[l];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,i<<1);
	build(m+1,r,(i<<1)+1);
	maximun[i]=max(maximun[i<<1],maximun[(i<<1)+1]);
	minimun[i]=min(minimun[i<<1],minimun[(i<<1)+1]);
}
int amax,amin,ll,rr;
void fd(int l,int r,int i)
{
	if(ll<=l&&r<=rr)
	{
		amax=max(amax,maximun[i]);
		amin=min(amin,minimun[i]);
		return;
	}
	int m=(l+r)>>1;
	if(ll<=m)
	{
		fd(l,m,i<<1);
	}
	if(m<rr)
	{
		fd(m+1,r,(i<<1)+1);
	}
}
int main()
{
	int a,b,c,d;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c;
		inin[i]=c;
	}
	build(1,a,1);
	for(int i=0;i<b;i++)
	{
		amax=0;
		amin=2147483647;
		cin>>ll>>rr;
		fd(1,a,1);
		cout<<amax-amin<<endl;
	}
	return 0;
}
