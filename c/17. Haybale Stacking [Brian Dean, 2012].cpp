#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,a,b;
	cin>>n>>k;
	int *x=new int[n+1],*y=new int[n+1],*s=new int[n];
	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		x[a]++;
		y[b]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=x[i];
		s[i-1]+=sum;
		sum-=y[i];
	}
	sort(s,s+n);
	cout<<s[((n+1)/2)-1];
	return 0;
}
