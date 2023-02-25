#include<iostream>
#include<math.h>
using namespace std;
bool y=true;
pair<char,char>p[5];
void go(string s) {
	if(s.size()==5) {
		bool yy=true;
		for(int i=0;i<5;i++) {
			if(s.find(p[i].first)>=s.find(p[i].second)) {
				yy=false;
				break;
			}
		}
		if(yy) {
			cout<<s;
			y=false;
		}
		return;
	} 
	
	for(int i=0;i<=4&&y;i++) {
		if(s.find('A'+i) == string::npos) {
			go(s+string(1,'A'+i));
		}
	}
}
int main() {
	string s;
	for(int i=0;i<5;i++) {
		cin>>s;
		if(s[1]=='<') {
			p[i]=pair<char,char>(s[0],s[2]);
		} else {
			p[i]=pair<char,char>(s[2],s[0]);
		}
	}
	go("");
	if(y) {
		cout<<"impossible";
	}
	return 0;
}
