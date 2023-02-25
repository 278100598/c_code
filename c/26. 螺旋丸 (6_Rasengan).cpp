#include<iostream>
#include<math.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int size=1;
	while(size*size<s.size()) {
		size+=2;
	}
	char c[size][size];
	int x=size/2,y=size/2,index=1;
	c[y][x]=s[0];
	x+=1;
	for(int i=3;i<=size;i+=2) {
		for(int j=1;j<=i-2;j++) {
			c[y][x]=(index<s.size()?s[index]:' ');
			index++;
			y-=1;
		}
		for(int j=1;j<=i-1;j++) {
			c[y][x]=(index<s.size()?s[index]:' ');
			index++;
			x-=1;
		}
		for(int j=1;j<=i-1;j++) {
			c[y][x]=(index<s.size()?s[index]:' ');
			index++;
			y+=1;
		}
		for(int j=1;j<=i;j++) {
			c[y][x]=(index<s.size()?s[index]:' ');
			index++;
			x+=1;
		}
	}
	int i=(c[0][size-1]==' '?1:0),j;
	for(i;i<(c[size-1][0]==' '?size-1:size);i++) {
		j=(c[0][0]==' '?1:0);
		for(j;j<size;j++) {
			if(j!=size-1||c[i][j]!=' '){
				cout<<c[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}
