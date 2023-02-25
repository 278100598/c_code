#include<iostream>
#include<vector>
using namespace std;
void matrix(vector<long long int>&x,vector<long long int>&y)
{
	vector<long long int>o;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<3;k++)
		{
			long long int sum=0;
			for(int j=0;j<3;j++)
			{
				sum+=(x[i*3+j]*y[j*3+k]);
			}
			o.push_back(sum%1000000007);
		}
	}
	x=o;
}
int main()
{
	int n;
	cin>>n;
	vector<long long int>x={1,1,1,1,0,0,0,0,1},answer={1,0,0,0,1,0,0,0,1};
	while(n!=0)
	{
		if(n%2)
		{
			matrix(answer,x);
		}
		matrix(x,x);
		n/=2;
	}
	cout<<answer[2];
	return 0;
}
