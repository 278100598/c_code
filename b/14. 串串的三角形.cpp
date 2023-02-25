#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b<=c)
	{
		cout<<"NULL";
	}
	else if(a*a+b*b==c*c)
	{
		cout<<"Right Triangle";
	}
	else if(a*a+b*b>c*c)
	{
		cout<<"Acute Triangle";
	}
	else
	{
		cout<<"Obtuse Triangle";
	}
	return 0;
} 
