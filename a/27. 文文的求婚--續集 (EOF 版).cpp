#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a;
	while(cin>>a&&a!=EOF)
	{ 
		if(a%400==0)
		{
			cout<<"a leap year"<<endl;
		}
		else if(a%4==0&&a%100!=0)
		{
			cout<<"a leap year"<<endl;
		}
		else
		{
			cout<<"a normal year"<<endl;
		}
	}
	return 0;
}
