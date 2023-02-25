#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a,b;
	while(cin>>a>>b)
	{ 
		if(7<=a&&a<17)
		{
			if(a==7&&b<30)
			{
				cout<<"Off School"<<endl;
			}
			else
			{
				cout<<"At School"<<endl;
			}
		}
		else
		{
			cout<<"Off School"<<endl;
		}
	}
	return 0;
}
