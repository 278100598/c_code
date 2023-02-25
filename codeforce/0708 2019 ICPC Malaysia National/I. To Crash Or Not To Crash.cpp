#include<iostream>
using namespace std;
int main()
{
	for(int r=0;r<3;r++) {
		string s;
		cin>>s;
		for(int i=0;i<10;i++) {
			if(s[i]=='=') {
				string out = "You shall pass!!!";
				bool y=true;
				for(int j=i+1;j<10&&y;j++) {
					if(s[j]!='.') {
						out=s[j];
						y=false;
					}
				}
				cout<<out;
			}
		}
	}
    return 0;
}
