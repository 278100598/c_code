#include<iostream>
using namespace std;
int main()
{
	string s,ss;
	bool t=true;
	cin>>s;
	ss=s;
	int i=1;
	while(cin>>s)
	{
		if(i==ss.size()||int(ss[i]|32)!=int(s[0]|32))
		{
			t=false;
			break;
		}
		i++;
	}
	cout<<((t&&i==ss.size())?"o\'_\'o":"QQ");
	return 0;
}
