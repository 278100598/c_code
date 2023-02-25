#include<iostream>
#include<vector>
using namespace std;
void matrix(vector<long long int>&x,vector<long long int>&y)
{
	vector<long long int>o;
	o.push_back((x[0]*y[0]+x[1]*y[2])%1000000007);
	o.push_back((x[0]*y[1]+x[1]*y[3])%1000000007);
	o.push_back((x[2]*y[0]+x[3]*y[2])%1000000007);
	o.push_back((x[2]*y[1]+x[3]*y[3])%1000000007);
	x=o;
}
int main()
{
	long long int a,b,x1,x2,n;
	cin>>x1>>x2>>a>>b>>n;
	vector<long long int>m={b,1,a,0},answer={1,0,0,1};
	n-=2;
	while(n!=0)
	{
		if(n%2)
		{
			matrix(answer,m);
		}
		matrix(m,m);
		n/=2;
	}
	cout<<(answer[0]*x2+answer[2]*x1)%1000000007;
	return 0;
}
