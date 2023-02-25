#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a,i=1,x;
    cin>>x; 
	while(x>0)
	{ 
		cin>>a;
		cout<<"Case "<<i<<": ";
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
		i++;
		x--;
	}
	return 0;
}
