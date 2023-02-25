#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%5==0||(a%2==0&&a%3==0&&a%7==0))
	{
		cout<<"Black";
	}
	else if(a%2==0&&a%3==0)
	{
		cout<<"Orange";
	}
	else if(a%3==0&&a%7==0)
	{
		cout<<"Green";
	}
	else if(a%2==0&&a%7==0)
	{
		cout<<"Purple";
	}
	else if(a%2==0)
	{
		cout<<"Red";
	}
	else if(a%3==0)
	{
		cout<<"Yellow";
	}
	else if(a%7==0)
	{
		cout<<"Blue";
	}
	else if(a%2==0&&a%7==0)
	{
		cout<<"Purple";
	}
	else
	{
		cout<<"White";
	}
	return 0;
} 
