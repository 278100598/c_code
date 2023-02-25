#include<iostream>
using namespace std;
int main()
{
	string s;
	int ii=0;
	while(getline(cin,s))
	{
		ii++;
		int dot=0,front0=0;
		bool out=true,nega=false,dd=true;
		if(s=="")
		{
			cout<<"Incorrect format!!!"<<endl;
			continue;
		}
		for(int i=0;i<s.size()&&out;i++)
		{
			if((s[i]<'0'||'9'<s[i])&&s[i]!='-'&&s[i]!='.')
			{
				out=false;
			}
			if(dd)
			{
				switch(s[i])
				{
					case '-':
						if(i!=0||s=="-")
						{
							out=false;
						}
						break;
					case '.':
						dot++;
						if(i==0||dot==2||i==s.size()-1||s=="-.")
						{
							out=false;
						}
						dd=false;
						break;
					case '0':
						if((i==0&&s.size()!=1&&s[1]!='.')||(s[0]=='-'&&i==1&&s.size()!=2&&s[2]!='.'))
						{
							out=false;
						}
				}
			}
			else
			{
				switch(s[i])
				{
					case '-':
						out=false;
						break;
					case '.':
						out=false;
						break;
					case '0':
						if(i==s.size()-1)
						{
							out=false;
						}
				}
			}
			
		}
		if(out)
		{	
			cout<<s<<endl;
		}
		else
		{
			cout<<"Incorrect format!!!"<<endl;
		}
	}
	return 0;
}
