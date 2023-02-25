#include<iostream>
#include<map>
using namespace std;
string s;
map<string,int>c;
int b(int index)
{
	int l=1;
	for(int i=index+1;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			l++;
		}
		else if(s[i]==')')
		{
			l--;
		}
		if(l==0)
		{
			return i;
		}
	}
}
void bracket(int index,int power,int last)
{
	string name="";
	//cout<<s.substr(index,last-index+1)<<" "<<power<<endl;
	for(int i=index+1;i<last;)
	{
		if(s[i]=='(')
		{
			int z=b(i),p,a;
			p=z+1;
			if(48<=s[p]&&s[p]<=57)
			{
				while(48<=s[p]&&s[p]<=57)p++;
				a=stoi(s.substr(z+1,p-z));
			}
			else a=1;
			bracket(i,power*a,z);
			i=p;
			continue;
		}
		else if(s[i]==')')
		{
			i++;
			continue;
		}
		else
		{
			int p,z;
			if(97<=s[i+1]&&s[i+1]<=122)
			{
				name=s.substr(i,2);
				z=i+1;
			}
			else
			{
				name=s[i];
				z=i;
			}
			p=z+1;
			if(48<=s[p]&&s[p]<=57)
			{
				while(48<=s[p]&&s[p]<=57)p++;
				z=stoi(s.substr(z+1,p-z));
			}
			else z=1;
			c[name]+=(z*power);
			i=p;
		}
	}
}
int main()
{
	cin>>s;
	cout<<s<<endl;
	s='('+s+')';
	bracket(0,1,s.size()-1);
	for(auto i:c)
	{
		cout<<i.first<<":"<<i.second<<endl;
	}
	return 0;
}
