#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x[26];
	for(int i;i<sizeof(x)/sizeof(x[0]);i++)
	{
		x[i]=0;
	}
	char a;
	while(cin>>a&&a!=EOF)
	{
		if(65<=int(a)&&int(a)<=90)
		{
			a=a+32;
		}
		if(97<=int(a)&&int(a)<=122)
		{
			x[int(a)-97]++;
		}
	}
	for(int i=0;i<26;i++)
	{
		if(x[i]!=0)
		{
			cout<<"'"<<char(i+97)<<"': "<<x[i]<<endl;
		}
	}
	return 0;
}
