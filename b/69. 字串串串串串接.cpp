#include<iostream>
using namespace std;
int main()
{
	string s[4],t,a="";
	cin>>s[1]>>s[2]>>s[3]>>t;
	for(int i=0;i<t.size();i++)
	{
		a+=s[int(t[i])-48];
	}
	cout<<a;
	return 0;
}
