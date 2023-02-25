#include<iostream>
using namespace std;
string s;
int mx,num;
void dfs(int begin,int end) {
	if(begin==-1||end==s.size()||s[begin]!=s[end]) {
		return;
	}
	if(min(begin*2+1,(int)(s.size()-end-1)*2)+end-begin+1<mx) {
		return;
	}
	if(begin==end && s[begin]==s[end+1]) {
		dfs(begin,end+1);
	}
	dfs(begin-1,end+1);
	if(mx<end-begin+1) {
		mx=end-begin+1;
		num=1;
	} else if(mx==end-begin+1) {
		num++;
	}
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		num=0;
		mx=0;
		cin>>s;
		int c=1;
		for(int i=1;i<s.size();i++) {
			if(s[i-1]==s[i])c++;
			else c=1;
			mx=max(mx,c);
		}
		for(int i=0;i<s.size();i++) {
			dfs(i,i);
		}
		cout<<mx<<" "<<num<<endl;
	}
	return 0;
}
