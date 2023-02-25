#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
	string n1,n2;
	cin>>n1>>n1>>n1;
	n1=n1.substr(1,n1.size()-2);
	cin>>n2>>n2>>n2;
	n2=n2.substr(1,n2.size()-2);
	long long int a=0,b=0,p=1;
	for(int i=n1.size()-1;i>=0;i--)
	{
		a+=int(n1[i]-48)*p;
		p*=10;
	}
	p=1;
	for(int i=n2.size()-1;i>=0;i--)
	{
		b+=int(n2[i]-48)*p;
		p*=10;
	}
	cout<<"sum = "<<a+b;
	return 0;
}
