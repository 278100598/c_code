#include<iostream>
using namespace std;
int *spring,k,n;
long long int *f;
int main()
{
	cin>>n>>k;
	spring=new int[n+1];
	f=new long long int[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>spring[i];
		f[i]=0;
	}
	f[1]=1;
	for(int i=0;i<k;i++)
	{
		for(int j=n;j>i;j--)
		{
			if(f[j]>0)
			{
				f[j]%=1000000009;
				for(int h=1;h<=spring[j]&&h+j<=n;h++)
				{
					f[j+h]+=f[j];
				}
				f[j]=0;
			}
		}
	}
	cout<<f[n]%1000000009;
	return 0;
}
