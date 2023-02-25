#include<iostream>
using namespace std;
int main()
{
	int n,re=1,now,power=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>now;
		if(now>re)
		{
			power+=(now-re)*3;
		}
		else
		{
			power+=(re-now)*2;
		}
		re=now;
	}
	cout<<power;
	return 0;
}
