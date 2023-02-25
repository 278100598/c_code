#include<iostream>
using namespace std;
string a[20][20];
int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		if(s1[0]==s2[0])
		{
			a[0][0]=s1[0];
		}
		else
		{
			a[0][0]="";
		}
		for(int i=1;i<20;i++)
		{
			if(s1[i]==s2[0])a[i][0]=s2[0];
			else a[i][0]=a[i-1][0];
			if(s1[0]==s2[i])a[0][i]=s1[0];
			else a[0][i]=a[0][i-1];
		}
		for(int i=1;i<s1.size();i++)
		{
			for(int j=1;j<s2.size();j++)
			{
				if(s1[i]==s2[j])
				{
					a[i][j]=a[i-1][j-1]+s1[i];
				}
				else
				{
					if(a[i-1][j].size()>a[i][j-1].size())
					{
						a[i][j]=a[i-1][j];
					}
					else
					{
						a[i][j]=a[i][j-1];
					}
				}
			}
		}
		cout<<s1<<" "<<s2<<" = ";
		if(a[s1.size()-1][s2.size()-1].empty())
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<a[s1.size()-1][s2.size()-1]<<endl;
		}
	}
	return 0;
}
