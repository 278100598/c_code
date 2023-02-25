#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%4==0&&a%100!=0)
	{
		cout<<"閏年";
	}
	else if(a%400==0) 
	{
		cout<<"閏年";
	}
	else
	{
		cout<<"平年";
	}
	return 0;
} 
