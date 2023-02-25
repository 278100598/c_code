#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	string s[n+1];
	for(int i=1;i<=n;i++) {
		getline(cin,s[i]);
		if(s[i]==""&&i==1) {
			i--;
		}
	}
	int now=1,v[26];
	for(int i=0;i<26;i++) v[i]=0;
	while(s[now]!="END") {
		string str=s[now],t="";
		if(str.find(" + ")!=string::npos) {
			int i=str.find(" + "),a,b;
			if('A'<=str[i-1]&&str[i-1]<='Z') {
				a=v[str[i-1]-'A'];
			} else {
				a=stoi(str.substr(str.find("=")+1));
			}
			if('A'<=str[i+3]&&str[i+3]<='Z') {
				b=v[str[i+3]-'A'];
			} else {
				b=stoi(str.substr(i+2));
			}
			v[str[0]-'A'] = a + b;
			t=to_string(1)+" "+to_string(str[0]-'A')+" "+to_string(a)+" "+to_string(b);
		}
		else if(str.find(" - ")!=string::npos) {
			int i=str.find(" - "),a,b;
			if('A'<=str[i-1]&&str[i-1]<='Z') {
				a=v[str[i-1]-'A'];
			} else {
				a=stoi(str.substr(str.find("=")+1));
			}
			if('A'<=str[i+3]&&str[i+3]<='Z') {
				b=v[str[i+3]-'A'];
			} else {
				b=stoi(str.substr(i+2));
			}
			v[str[0]-'A'] = a - b;
			t=to_string(2)+" "+to_string(str[0]-'A')+" "+to_string(a)+" "+to_string(b);
		}
		else if(str.find(" * ")!=string::npos) {
			int i=str.find(" * "),a,b;
			if('A'<=str[i-1]&&str[i-1]<='Z') {
				a=v[str[i-1]-'A'];
			} else {
				a=stoi(str.substr(str.find("=")+1));
			}
			if('A'<=str[i+3]&&str[i+3]<='Z') {
				b=v[str[i+3]-'A'];
			} else {
				b=stoi(str.substr(i+2));
			}
			v[str[0]-'A'] = a * b;
			t=to_string(3)+" "+to_string(str[0]-'A')+" "+to_string(a)+" "+to_string(b);
		}
		else if(str.find("IF")!=string::npos) {
			int a,b;
			bool c;
			if('A'<=str[3]&&str[3]<='Z') {
				a=v[str[3]-'A'];
			} else {
				a=stoi(str.substr(3));
			}
			if('A'<=str[str.find("THEN")-2]&&str[str.find("THEN")-2]<='Z') {
				b=v[str[str.find("THEN")-2]-'A'];
			} else {
				b=stoi(str.substr(str.substr(0,str.find("THEN")-2).find_last_of(" ")));
			}
			
			if(str.find("<>")!=string::npos) {
				c = (a!=b);
			} else if(str.find("<=")!=string::npos) {
				c = (a<=b);
			} else if(str.find(">=")!=string::npos) {
				c = (a>=b);
			} else if(str.find("=")!=string::npos) {
				c = (a==b);
			} else if(str.find("<")!=string::npos) {
				c = (a<b);
			} else if(str.find(">")!=string::npos) {
				c = (a>b);
			}
			
			if(c) {
				now=stoi(str.substr(str.find("THEN GOTO")+9))-1;
			} else {
				now=stoi(str.substr(str.find("ELSE GOTO")+9))-1;
			}
			t=to_string(4)+" "+to_string(a)+" "+to_string(b)+" "+to_string(c);
		}
		else if(str.find("=")!=string::npos) {
			int x;
			if('A'<=str[4]&&str[4]<='Z') {
				x=v[str[4]-'A'];
			} else {
				x=stoi(str.substr(3));
			} 
			v[str[0]-'A'] = x;
			t=to_string(5)+" "+to_string(str[0]-'A')+" "+to_string(x);
		}
		else if(str.find("PRINT")!=string::npos) {
			int x;
			if('A'<=str[6]&&str[6]<='Z') {
				x=v[str[6]-'A'];
			} else {
				x=stoi(str.substr(6));
			}
			cout<<x<<endl;
			t=to_string(6)+" "+to_string(str[0]-'A')+" "+to_string(x);
		}
		now++;
		//cout<<v[0]<<" "<<v[1]<<endl;
	}
	return 0;
}
/*
11
A = 1024
B = 72
A = A - B
PRINT A
IF A > B THEN GOTO 3 ELSE GOTO 6
B = A + B
A = B - A
B = B - A
IF B = 0 THEN GOTO 10 ELSE GOTO 3
PRINT A
END
*/
/*
24
N = 1000
X = 1



IF R <> 0
*/
