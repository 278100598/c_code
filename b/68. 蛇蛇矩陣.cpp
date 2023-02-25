#include<iostream>
using namespace std;
int main()
{
	int n;
	bool right=true;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(right)
		{
			for(int j=n*(i-1)+1;j<=n*i;j++)
			{
				cout<<j<<" ";
			}
			cout<<endl;
			right=false;
		}
		else
		{
			for(int j=n*i;j>n*(i-1);j--)
			{
				cout<<j<<" ";
			}
			cout<<endl;
			right=true;
		}
	}
	return 0;
}
