#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a*b+c>=60*a)
	{
		cout<<"PASS";
	}
	else
	{
		cout<<"FAIL";
	}
	return 0;
} 
