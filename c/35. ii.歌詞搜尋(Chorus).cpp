#include<iostream>
using namespace std;
int main() {
	string s[200];
	int size=0,begin=0,end=-1,mx=0,tmp=-1;
	while(getline(cin,s[size])) {
		size++;
	}
	for(int i=0;i<size/2+1;i++) {
		for(int j=i+1;j<size;j++) {
			for(int k=1;k+j-i+1<size;k++) {
				bool y=true;
				for(int l=k;l<=k+j-i;l++) {
					if(s[i+l-k]!=s[j+l]) {
						y=false;
						break;
					}
				}
				if(y && end-begin < j-i) {
					end=j;
					begin=i;
				}
			}
			
		}
	}
	for(int i=begin;i<=end;i++) {
		cout<<s[i]<<endl;
	}
	return 0;
}
