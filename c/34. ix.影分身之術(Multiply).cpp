#include<iostream>
using namespace std;
int main() {
	int n,size=1;
	cin>>n;
	string *s=new string[size];
	s[0]="X";
	for(int i=0;i<n;i++) {
		string *ss=new string[size*3];
		for(int j=0;j<size;j++) {
			ss[j]=string(size,' ')+s[j]+string(size,' ');
		}
		for(int j=0;j<size;j++) {
			ss[j+size]=s[j]+s[j]+s[j];
		}
		for(int j=0;j<size;j++) {
			ss[j+size*2]=string(size,' ')+s[j]+string(size,' ');
		}
		s=ss;
		size*=3;
	}
	for(int i=0;i<size;i++) {
		cout<<s[i]<<endl;
	}
	
	return 0;
}
