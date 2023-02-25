#include<iostream>
using namespace std;
int x[2000001],*h;
void build(int l,int r,int index)
{
	if(l==r)
	{
		x[index]=h[l];
		return;
	}
	build(l,(l+r)/2,index*2);
	build((l+r)/2+1,r,index*2+1);
	x[index]=min(x[index*2],x[index*2+1]);
	return;
}
int find(int a,int b,int l,int r,int index)
{
	if(a<=l&&r<=b)
	{
		return x[index];
	}
	else if(r<a||b<l)
	{
		return 2000001;
	}
	return min(find(a,b,l,(l+r)/2,index*2),find(a,b,(l+r)/2+1,r,index*2+1));
}
int main()
{
	int n,a,b;
	cin>>n;
	h=new int[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	build(1,n,1);
	while(cin>>a>>b)
	{
		cout<<find(a,b,1,n,1)+1<<endl;
	}
	return 0;
}
