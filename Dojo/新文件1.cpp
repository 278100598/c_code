#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int>*x;
int find(int l,int r,int t)
{
	int m=(l+r)/2;
	if(x[m].first==t)return x[m].second;
	if(l==r)return -1;
	else if(x[m].first<t)
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q,a;
	cin>>n;
	x=new pair<int,int>[n]{};
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		x[i-1]=pair<int,int>(a,i);
	}
	sort(x,x+n);
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>a;
		cout<<find(0,n-1,a)<<endl;
	}
	return 0;
} 
