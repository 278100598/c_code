#include<iostream>
using namespace std;
int T;
string s;

int main() {
	cin>>T;
	while(T--) {
		cin>>s;
		string ans=s;
		for(int i=1;i<s.size();i++) {
			char c=s[0];
			s.erase(0,1);
			s += c;
			if(s < ans) ans=s;
		}
		cout<<ans<<'\n';
		
	}
	
	
	return 0;
}
