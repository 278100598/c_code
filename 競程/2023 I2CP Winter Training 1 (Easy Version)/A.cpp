#include<iostream>
using namespace std;
string s;

int main() {
	bool fs=true;
	while(getline(cin,s)) {
		string x="";
		for(char c:s) {
			if(c=='"') {
				if(fs) x += "``";
				else x+= "''";
				
				fs ^= 1;
			} else x+=c;
		}
		cout<<x<<'\n';
	}
	
	return 0;
}
