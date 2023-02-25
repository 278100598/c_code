#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	bool p=true;
	string s,r;
	cin>>s;
	r=s;
	reverse(r.begin(),r.end());
	for(int i=0;i<s.size()/2+1;i++)
	{
		if(s[i]!=r[i])
		{
			p=false;
			break;
		}
	}
	cout<<((p)?"YES":"NO");
	return 0;
}
