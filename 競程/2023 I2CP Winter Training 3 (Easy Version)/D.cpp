#include<iostream>
#include<set>
using namespace std;
char mine[13]={'A','H','I','M','O','T','U','V','W','X','Y','1','8'};
set<char> me;

bool normal(string s) {
	for(int i=0;i<=s.size()/2;i++) {
		if(s[i]!=s[s.size()-1-i]) return false;
	}
	return true;
}

bool mirror(string s) {
	for(int i=0;i<=s.size()/2;i++) {
		if(me.count(s[i]) && s[s.size()-1-i]==s[i]);
		else if(s[i]=='E'&&s[s.size()-1-i]=='3');
		else if(s[i]=='3'&&s[s.size()-1-i]=='E');
		else if(s[i]=='J'&&s[s.size()-1-i]=='L');
		else if(s[i]=='L'&&s[s.size()-1-i]=='J');
		else if(s[i]=='S'&&s[s.size()-1-i]=='2');
		else if(s[i]=='2'&&s[s.size()-1-i]=='S');
		else if(s[i]=='Z'&&s[s.size()-1-i]=='5');
		else if(s[i]=='5'&&s[s.size()-1-i]=='Z');
		else return false;
	}
	return true;
}

int main() {
	for(int i=0;i<13;i++) me.insert(mine[i]);
	
	string s;
	while(cin>>s) {
		bool a=normal(s),b=mirror(s);
		cout<<s<<' ';
		if(a&&b) cout<<"-- is a mirrored palindrome.\n\n";
		else if(a) cout<<"-- is a regular palindrome.\n\n";
		else if(b) cout<<"-- is a mirrored string.\n\n";
		else cout<<"-- is not a palindrome.\n\n";
		
	}
	
	return 0;
}
