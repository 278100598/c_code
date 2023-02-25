#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,max=-1,mini=101,mi,ni;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b;
		if(max<b)
		{
			max=b;
			mi=i;
		}
		if(mini>b)
		{
			mini=b;
			ni=i;
		}
	}
	cout<<mi<<" "<<max<<" "<<ni<<" "<<mini; 
	return 0;
}
