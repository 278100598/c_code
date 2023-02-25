#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	char x[7]; 
	while(cin>>x)
	{
		for(int i=0;i<6;i++)
		{
			a=int(x[i]);
			b=int(x[i+1]);
			if(a>=b)
			c=a-b;
			else
			c=b-a;;
			cout<<c;
		}
		cout<<"\n";
	}
	return 0;
}
