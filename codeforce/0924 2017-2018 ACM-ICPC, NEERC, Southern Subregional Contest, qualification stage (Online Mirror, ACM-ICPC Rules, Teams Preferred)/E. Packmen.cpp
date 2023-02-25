#include<iostream>
using namespace std;
int N;
string s;

bool check(int x) {
	int pre = -1,cover = -1;
	for(int i=0;i<s.size();i++) {
		if(s[i] == 'P') {
			if(pre == -1) pre = i;
			int need = i - pre;
			if(x < need) return false;
			
			cover = i + max((x - need)/2,x - 2*need);
			pre = -1;
		} else if(s[i] == '*') {
			if(pre == -1 && cover < i) pre = i;
		}
	}
	
	if(pre != -1) return false;
	else return true;
}

int main() {
	cin>>N>>s;
	int l=0,r=2*N;
	while(l!=r) {
		int m=(l+r)/2;
		
		if(check(m)) r = m;
		else l = m+1;
	}
	cout<<r;
	return 0;
}
