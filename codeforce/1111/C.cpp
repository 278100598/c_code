#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair 
#define F first
#define S second
using namespace std;
long long int N,P;
vector<pair<pii,pii>> v;
bool cmp(pair<pii,pii> &a,pair<pii,pii> &b) {
	int x=min(a.F.S,a.S.S),y=min(b.F.S,b.S.S);
	return x<y;
}

int main() {
	cin>>N>>P;
	for(int i=0;i<N;i++) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a>c) {
			swap(a,c);
			swap(b,d);
		}
		v.emplace_back(mp(a,b),mp(c,d));
	}
	sort(v.begin(),v.end(),cmp);
	
	while(!v.empty()) {
		auto i=v.back();
		v.pop_back();
		while(!(i.F.F <= P && P <= i.S.F) && !v.empty()) {
			i=v.back();
			v.pop_back();
		}
		if(v.empty() && !(i.F.F <= P && P <= i.S.F)) break;
		
		if(min(i.F.S,i.S.S) == i.F.S) {
			P=i.F.F;
		} else {
			P=i.S.F;
		}
	}
	
	cout<<P;
	return 0;
}
/*
2 6
1 1 2 2
3 3 4 4

*/
