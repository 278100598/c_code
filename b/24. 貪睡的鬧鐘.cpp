#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,e;
	cin>>s>>e;
	int sh=(s[0]-48)*10+(s[1]-48),sm=(s[2]-48)*10+(s[3]-48),eh=(e[0]-48)*10+(e[1]-48),em=(e[2]-48)*10+(e[3]-48);
	int time=(((eh-sh)+24)%24)*60+(em-sm);
	for(int i=0;i<time;i+=5)
	{
		cout<<s<<endl;
		if(s[3]-48<5)
		{
			s[3]+=5;
		}
		else
		{
			s[3]-=5;
			if(s[2]-48<5)
			{
				s[2]+=1;
			}
			else
			{
				s[2]='0';
				if(s[1]-48<3)
				{
					s[1]+=1;
				}
				else
				{
					s[1]='0';
					if(s[0]-48<2)
					{
						s[0]+=1;
					}
					else
					{
						s[0]='0';
					}
				}
			}
		}
	}
	cout<<e;
	return 0;
}
