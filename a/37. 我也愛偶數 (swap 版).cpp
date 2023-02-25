#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a,b,s;
	while(cin>>a>>b)
	{
		if(a>b)
		{
			s=a;
			a=b;
			b=s;
		}
		if(a%2==0&&b%2==0)
		{
			s=(b/2)-(a/2)+1;
			s*=((a/2)+(b/2));
		}
		else if(a%2==0&&b%2==1)
		{
			s=(b/2)-(a/2)+1;
			s*=((a/2)+(b/2));
		}
		else if(a%2==1&&b%2==0)
		{
			s=(b/2)-(a/2);
			s*=((a/2+1)+(b/2));
		}
		else
		{
			s=(b/2)-(a/2);
			s*=((a/2+1)+(b/2));
		}
		cout<<s<<endl;
	}
	return 0;
}
	
