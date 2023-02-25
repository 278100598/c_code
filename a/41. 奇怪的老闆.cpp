#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long int maximun[50000][20],minimun[50000][20];
void build(vector<long long int> x)
{
	long long int len;
	len = x.size();
	for(long long int i=0;i<len;i++)
	{
		maximun[i][0]=x[i];
		minimun[i][0]=x[i];
	}
	for(long long int j=1;j<len;j++)
	{
		for(long long int i=0;i+(1<<j)-1<len;i++)
		{
			maximun[i][j]=max(maximun[i][j-1],maximun[i+(1<<(j-1))][j-1]);
			minimun[i][j]=min(minimun[i][j-1],minimun[i+(1<<(j-1))][j-1]);
		}
	}
}
long long int maxlr(long long int l,long long int r)
{
	long long int i=0,m=0;
	while((1<<i)<r-l+1)
	{
		i++;
	}
	if(i==0)
	{
		return maximun[l-1][0];
	}
	else
	{	
		return max(maximun[l-1][i-1],maximun[r-(1<<(i-1))][i-1]);
	}
	
}
long long int minlr(long long int l,long long int r)
{
	long long int i=0,m=0;
	while((1<<i)<r-l+1)
	{
		i++;
	}
	if(i==0)
	{
		return minimun[l-1][0];
	}
	else
	{	
		return min(minimun[l-1][i-1],minimun[r-(1<<(i-1))][i-1]);
	}
}
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    long long int a,b,l,r,c;
	vector<long long int> x;
	cin>>a>>b;
	for(long long int i=0;i<a;i++)
	{
		cin>>c;
		x.push_back(c);
	}
	build(x);
	for(long long int i=0;i<b;i++)
	{
		long long int m,n;
		cin>>l>>r;
		m=maxlr(l,r);
		n=minlr(l,r);
		cout<<m-n<<endl;
	}
	return 0;
}
