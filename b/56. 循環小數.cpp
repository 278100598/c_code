#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int t,n,m,f,s;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>m;
		cout<<n/m<<".";
		s=n%m;
		f=n%m;
		do
		{
			s=(s*10)%m;
			f=(f*100)%m;
		}while(f!=s);
		s=n%m;
		while(s!=f)
		{
			s*=10;
			cout<<s/m;
			s%=m;
			f=(f*10)%m;
		}
		cout<<"(";
		do
		{
			s*=10;
			cout<<s/m;
			s%=m;
		}while(s!=f);
		cout<<")"<<endl;
	}
	return 0;
}
