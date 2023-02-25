#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m=0,k=0,d2=0,d1=0,d=1,t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		k=(k+1)/2;
		m+=80-d;
		k+=(m<=0?(m+d)*20:d*20);
		if(m<=0)
		{
			int n=k*19/400;
			m=n;
			k-=n*20;
			d2=0;
			d1=0;
			d=1;
			continue;
		}
		d2=d1;
		d1=d;
		d=d2+d1;
	}
	cout<<m;
	return 0;
}
