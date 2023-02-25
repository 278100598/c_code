#include<iostream>
using namespace std;
int main()
{
	int n,a;
	bool x=true;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a==1)
		{
			x=false;
			break;
		}
	}
	if(x)
	{
		cout<<"YES"<<endl<<0<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
