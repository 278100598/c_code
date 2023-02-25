#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<map>
#define pii pair<int,int>
using namespace std;
int N,num[51];
map<pii,int> m[51][51];

int SG(int l,int lv,int r,int rv) {
	if(m[l][r].find(pii(lv,rv)) != m[l][r].end()) return m[l][r][pii(lv,rv)];
	
	if(l==r) return 0;
	if(l+1==r) return (__gcd(lv,rv) == 1 ? 0:1);
	
	unordered_set<int> st;
	int x=__gcd(lv,num[l+1]);
	if(x!=1) st.insert(SG(l+1,num[l+1]/x,r,rv));
	
	for(int i=l+1;i<r-1;i++) {
		x=__gcd(num[i],num[i+1]);
		if(x!=1) st.insert(SG(l,lv,i,num[i]/x) ^ SG(i+1,num[i+1]/x,r,rv));
	}
	
	x=__gcd(num[r-1],rv);
	if(x!=1) st.insert(SG(l,lv,r-1,num[r-1]/x));
	
	int val=0;
	while(st.find(val) != st.end()) val++;
	m[l][r][pii(lv,rv)]=val;
	//cout<<l<<" "<<r<<" "<<val<<endl;
	return val;
}

int main() {
	cin>>N;
	for(int i=1;i<=N;i++) cin>>num[i];
	if(SG(1,num[1],N,num[N]) != 0) cout<<"Alice";
	else cout<<"Bob";
	
	return 0;
}
