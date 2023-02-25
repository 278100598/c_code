#include<iostream>
using namespace std;
int c[(1<<19)],keep[19][19];

bool is(char c) {
	return (c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='w'&&c!='y');
}

int get(char c) {
	int r=0;
	for(int i='a';i<c;i++) {
		if(i!='a'&&i!='e'&&i!='i'&&i!='o'&&i!='u'&&i!='w'&&i!='y') {
			r++;
		}
	}
	return r;
}

int main() {
	freopen("consonant.in","r",stdin);    // Åª file.in ÀÉ
	freopen("consonant.out","w",stdout);  // ¼g¤J file.out ÀÉ
	for(int i=0;i<19;i++) {
		for(int j=0;j<19;j++) keep[i][j]=0;
	}
	string s;
	cin>>s;
	char pre=s[0];
	for(int i=1;i<s.size();i++) {
		if(is(pre)&&is(s[i])) {
			keep[get(pre)][get(s[i])]+=1;
			keep[get(s[i])][get(pre)]+=1;
		}
		pre=s[i];
	}
	/*
	for(int i='a';i<='z';i++) {
		for(int j='a';j<='z';j++) {
			if(is(char(i))&&is(char(j))&&keep[get(char(i))][get(char(j))]!=0) {
				cout<<char(i)<<" "<<char(j)<<" "<<keep[get(char(i))][get(char(j))]<<endl;
			}
		}
	}*/
	int mx=0,record=0;
	for(int i=1;i<(1<<19);i++) {
		int now=0;
		for(int j=0;j<19;j++) {
			bool a=i&(1<<j);
			for(int k=j+1;k<19;k++) {
				bool b=i&(1<<k);
				if(a^b) {
					now+=keep[j][k];
				}
			}
		}
		if(now>mx) {
			mx=now;
			record=i;
		}
	}
	for(int i=0;i<s.size();i++) {
		if(is(s[i])&&(record&(1<<get(s[i])))) {
			s[i]=(s[i]-'a'+'A');
		}
	}
	cout<<s;
	return 0;
} 
