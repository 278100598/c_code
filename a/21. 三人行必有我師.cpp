#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a,b,c;
	while(cin>>a>>b>>c)
	{ 
		if(a>b&&a>c)
		{
			cout<<a<<endl;
		}
		else
		{
			cout<<max(b,c)<<endl;
		}
	}
	return 0;
}
