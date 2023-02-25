#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	int a;
	while(cin>>a)
	{
		int i=a%12;
		if(i==0)
		{
			cout<<"Monkey"<<endl;
		}
		else if(i==1)
		{
			cout<<"Rooster"<<endl;
		}
		else if(i==2)
		{
			cout<<"Dog"<<endl;
		}
		else if(i==3)
		{
			cout<<"Pig"<<endl;
		}
		else if(i==4)
		{
			cout<<"Rat"<<endl;
		}
		else if(i==5)
		{
			cout<<"Ox"<<endl;
		}
		else if(i==6)
		{
			cout<<"Tiger"<<endl;
		}
		else if(i==7)
		{
			cout<<"Hare"<<endl;
		}
		else if(i==8)
		{
			cout<<"Dragon"<<endl;
		}
		else if(i==9)
		{
			cout<<"Snake"<<endl;
		}
		else if(i==10)
		{
			cout<<"Horse"<<endl;
		}
		else if(i==11)
		{
			cout<<"Sheep"<<endl;
		}
	}
	return 0;
} 
