#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a,b,x=0;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		if(i%400==0)
		{
			x++;
		}
		else if(i%4==0&&i%100!=0)
		{
			x++;
		}
	}
	cout<<x;
	return 0;
}
