#include<iostream>
#include<algorithm>
using namespace std;
string tt(int x)
{
	string s="";
	while(x!=0)
	{
		s+=char((x%10)+48);
		x/=10;
	} 
	reverse(s.begin(),s.end());
	return s;
}
int main()
{
	string s,ss="";
	char re;
	cin>>s>>s;
	re=s[0];
	int c=1;
	for(int i=1;i<s.size();i++)
	{
		if(re==s[i])
		{
			c++;
		}
		else
		{
			ss+=tt(c);
			ss+=re;
			re=s[i];
			c=1;
		}
	}
	ss+=tt(c);
	ss+=re;
	cout<<((ss.size()<s.size())?ss:s);
	return 0;
} 
