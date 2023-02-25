#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		vector<int>x,y;
		for(int j=0;j<b;j++)
		{
			cin>>c;
			x.push_back(c);
		}
		for(int j=0;j<b;j++)
		{
			cin>>c;
			y.push_back(c);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		int sum=0;
		for(int j=0;j<b;j++)
		{
			sum+=x[j]*y[j];
		}
		cout<<sum<<endl;
	}
	return 0;
}
