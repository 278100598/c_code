#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int spring[n+1];
	long long int **f=new long long int*[n+1];
	for(int i=1;i<=n;i++)
	{
		f[i]=new long long int[k+1]{};
	}
	for(int i=1;i<=n;i++)
	{
		cin>>spring[i];
	}
	f[1][k]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=spring[i]&&i+j<=n;j++)
		{
			for(int q=min(k,n-i);q>=k-i+1&&q>0;q--)
			{
				//cout<<i+j<<" "<<q-1<<" "<<i<<" "<<q<<" "<<endl;
				//cout<<f[i+j][q-1]<<" "<<f[i][q]<<endl;
				f[i+j][q-1]+=f[i][q];
				//cout<<f[i+j][q-1]<<" "<<f[i][q]<<endl<<endl;
			}
			
		}
		for(int q=min(k,n-i);q>=k-i+1&&q>0;q--)
		{
			f[i+1][q]%=1000000009;
		}
	}
	cout<<f[n][0]%1000000009;
	return 0;
}
