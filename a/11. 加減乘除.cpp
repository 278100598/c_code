#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int x,y;
    string z;
	while(cin>>x>>z>>y)
	{
		if(z=="+")
		cout<<x+y;
		else if(z=="-")
		cout<<x-y;
		else if(z=="*")
		cout<<x*y;
		else if(z=="/")
		cout<<x/y;
		cout<<endl;
	}
	return 0;
}
