#include<iostream>
using namespace std;
int N;
bool b[1000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N+1;i++) b[i]=true;
	for(int i=0;i<N;i++) {
		string s;
		cin>>s;
		if(s.size()>9)continue;
		if(0<=stoi(s)&&stoi(s)<=1000000) b[stoi(s)]=false;
	}
	for(int i=0;i<=N;i++) {
		if(b[i]) {
			cout<<i;
			break;
		}
	}
	return 0;
}
