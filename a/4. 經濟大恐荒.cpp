#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b=0,c; 
	while(cin>>a)
	{
		int x[a];
		for(int i=0;i<a;i++)
		cin>>x[i];
		for(int i=1;i<=a;i++)
		{
			b+=i*x[i-1];
		}
		cout<<b<<"\n";
	}
	return 0;
}
