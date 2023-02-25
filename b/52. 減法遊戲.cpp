#include<iostream>
using namespace std;
long long int x[500000],f[500000];
int n;
int main()
{
	int a;
	long long int ans;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	f[0]=x[0];
	ans=x[0];
	for(int i=1;i<n;i++)
	{
		//cout<<f[i-1]<<" "<<f[i-1]-x[i]<<" "<<x[i]<<endl;
		long long int m=max(f[i-1]-x[i],static_cast<long long int>(x[i]));
		f[i]=m;
		ans=max(m,ans);
	}
	cout<<ans;
	return 0;
}
