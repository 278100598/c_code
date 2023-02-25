#include<iostream>
using namespace std;
char **c;
int main() {
	int n;
	cin>>n;
	c = new char*[n];
	string s;
	cin>>s;
	for(int i=0;i<n;i++) {
		c[i]=new char[n];
		for(int j=0;j<n;j++) {
			cin>>c[i][j];
		}
	}
	int a=0;
	for(int i=0;i<s.size();i++) {
		if(s[i]=='L') {
			a = (a+3)%4;
		}
		if(s[i]=='R') {
			a = (a+1)%4; 
		}
	}
	if(a==0) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout<<c[i][j];
			}
			cout<<endl;
		}
	} else if(a==3) {
		for(int i=n-1;i>=0;i--) {
			for(int j=0;j<n;j++) {
				if(c[j][i]=='v') cout<<'>';
				if(c[j][i]=='>') cout<<'^';
				if(c[j][i]=='^') cout<<'<';
				if(c[j][i]=='<') cout<<'v';
				if(c[j][i]=='.') cout<<'.';
			}
			cout<<endl;
		}
	} else if(a==2) {
		for(int i=n-1;i>=0;i--) {
			for(int j=n-1;j>=0;j--) {
				if(c[i][j]=='v') cout<<'^';
				if(c[i][j]=='>') cout<<'<';
				if(c[i][j]=='^') cout<<'v';
				if(c[i][j]=='<') cout<<'>';
				if(c[i][j]=='.') cout<<'.';
			}
			cout<<endl;
		}
	} else if(a==1) {
		for(int i=0;i<n;i++) {
			for(int j=n-1;j>=0;j--) {
				if(c[j][i]=='v') cout<<'<';
				if(c[j][i]=='>') cout<<'v';
				if(c[j][i]=='^') cout<<'>';
				if(c[j][i]=='<') cout<<'^';
				if(c[j][i]=='.') cout<<'.';
			}
			cout<<endl;
		}
	} 
	return 0;
}
