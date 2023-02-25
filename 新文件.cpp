#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int n,q;
	while(cin>>n>>q)
	{
		int life[n];
		int h;
		cin>>h;
		life[0]=h;
		for(int i=1;i<n;i++)
		{
			cin>>h;
			life[i]=life[i-1]+h;
		}
		int att,nowatt=0,r=n-1,l=0,mid;
		for(int i=0;i<q;i++)
		{
			mid=(r+l)/2;
			cin>>att;
			nowatt+=att;
			if(nowatt>=life[n-1])
			{
				nowatt=0;
			}
			int cc=1;
			while(cc==1)
			if(life[mid]>nowatt)
			{
				r=mid;
			}
			if(life[mid]<nowatt)
			{
				l=mid;
			}
			if(life[mid]==nowatt)
			{
				cc=0;
			}
			if(life[mid]-1<nowatt&&life[mid]>nowatt)
			{
				cc=0;
			}
		}		
		cout<<mid;
	}
	return 0;
}

