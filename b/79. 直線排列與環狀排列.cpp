#include<iostream>
using namespace std;
long long int n,d=1000000007;
void matrix(long long int (&x)[2][2],long long int (&y)[2][2])
{
	long long int z[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			long long int m=0;
			for(int k=0;k<2;k++)
			{
				m+=(x[i][k])*(y[k][j]);
			}
			z[i][j]=m%d;
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)x[i][j]=z[i][j];
	}
}
int main()
{
	long long int nn;
	cin>>n;
	nn=n;
	long long int answer[2][2]={{1,0},{0,1}};
	long long int e[2][2]={{0,1},{1,1}};
	while(n!=0)
	{
		if(n%2==1)
		{
			matrix(answer,e);
		}
		matrix(e,e);
		n/=2;
	}
	cout<<(answer[0][0]+answer[1][0])%d<<endl;
	cout<<(nn==2?2:(answer[0][0]*2+answer[1][0])%d);
	return 0;
}
