#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c;
	while(cin>>c)
	{
		switch(c)
		{
			case 'A':
				cout<<'U';
				break;
			case 'T':
				cout<<'A';
				break;
			case 'C':
				cout<<'G';
				break;
			case 'G':
				cout<<'C';
				break;
		}
	}
	return 0;
}
