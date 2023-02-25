#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b,c;
	while(cin>>a>>b>>c)
	{
		
		if(a>b&&a>c)
		{
			cout<<(a>b+c?"A":(b>c?"B":"C"))<<endl;
		}
		else if(b>a&&b>c)
		{
			cout<<(b>a+c?"B":(a>c?"A":"C"))<<endl;
		}
		else
		{
			cout<<(c>a+b?"C":(a>b?"A":"B"))<<endl;
		}
	}
	return 0;
}
