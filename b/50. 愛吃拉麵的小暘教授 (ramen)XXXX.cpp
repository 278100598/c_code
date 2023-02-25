#include<iostream>
#include <algorithm>
using namespace std;
int n;
long long int f[500002];
pair<int,pair<int,long long int> >x[500002];
long long int money(int mn,int mm)
{
	//cout<<"in "<<mn<<" "<<mm<<endl;
	if(mn==mm)
	{
		f[mm]=0;
		return 0;
	}
	else
	{
		long long int m=money(mn,mm-1);
		long long int a,c;
		while(x[n].first==mm)
		{
			a=x[n].second.first;
			c=x[n].second.second;
			n--;
			m=max(m,f[a]+c);
			if(n==-1)
			{
				break;
			}
		}
		//cout<<"out "<<mn<<" "<<mm<<" "<<m<<endl;
		f[mm]=m;
		return m;
	}
}
bool cc(pair<int,pair<int,long long int> >x,pair<int,pair<int,long long int> >y)
{
	return x.first>y.first;
}
int main()
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	long long int mn=500001,mm=-1,a,b,c;
	cin>>n;
	if(n==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			mn=min(mn,a);
			mm=max(mm,b);
			x[i]=pair<int,pair<int,long long int> >(b,pair<int,long long int>(a,c));
		}	
		sort(x,x+n,cc);
		n--;
		cout<<money(mn,mm)<<endl;
	}
	return 0;
}
