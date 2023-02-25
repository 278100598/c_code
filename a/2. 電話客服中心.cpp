#include<iostream>
using namespace std;
int main()
{
	int a,x,y,z;
	int b[27]={0,10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	while(cin>>a)
	{
		z=0;
		int a1=a;
		for(int i=0;i<8;i++)
		{
			a1=a1/10;
			z+=(a1%10)*(i+1);
		}
		for(int i=1;i<=26;i++)
		{
			int a2=b[i];
			if(10-((a2/10+(a2%10)*9+z)%10)==10&&a%10==0)
			{
				cout<<(char)(i+64);
			}
			else if(10-((a2/10+(a2%10)*9+z)%10)==a%10)
			{
				cout<<(char)(i+64);
			}
		}
		cout<<"\n";
	}
	return 0;
}
