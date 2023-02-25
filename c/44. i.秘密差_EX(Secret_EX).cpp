#include<iostream>
#include<map>
using namespace std;
int main() {
	string s,ss;
	cin>>s>>ss;
	long long int sum=0,total=0,y;
	if(ss.size()<=7) {
		y=stoi(ss);
	}
	map<int,int>m;
	m[0]=1;
	for(int i=0;i<s.size()&&ss.size()<=7;i++) {
		int j=s[i]-'0';
		if(i%2==0) {
			sum+=j;
		} else {
			sum-=j;
		}
		if(m.find(sum-y)!=m.end()) {
			total+=m[sum-y];
		}
		if(m.find(y+sum)!=m.end() && sum-y!=y+sum) {
			total+=m[y+sum];
		}
		m[sum]++;
	}
	if(ss.size()>7) {
		cout<<0;
	} else {
		cout<<total;
	}
	return 0;
}
