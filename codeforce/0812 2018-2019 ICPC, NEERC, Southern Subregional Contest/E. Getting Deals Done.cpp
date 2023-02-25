#include<iostream>
#include<set>
#include<vector>
#define ll long long int
using namespace std;
ll C,N,M,T,cases[200000];
set<int> st;
vector<int> vec;
pair<int,int> ans;

bool check(int x) {
	ll time=0,work=0,num=0,need_break=0;
	for(int i=0;i<N;i++) {
		if(cases[i]>x) continue;
		
		if(num==M) {
			time+=need_break;
			need_break=0;
			num=0;
		}
		
		need_break+=cases[i];
		time+=cases[i];
		num++;
		
		if(time<=T) {
			work++;
		} else {
			break;
		}
	}
	
	if(ans.first < work) ans = make_pair(work,x);
	
	if(time>T) return false;
	else return true;
}

void two(int l, int r) {
	
	int m=(l+r)/2;
	//cout<<l<<" "<<r<<" "<<m<<" "<<check(vec[m])<<endl;
	if(l==r) {
		check(vec[m]);
		return;
	}
	
	if(check(vec[m])) {
		two(m+1,r);
	} else {
		two(l,m);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C;
	while(C--) {
		cin>>N>>M>>T;
		ans=make_pair(-1,-1);
		vec.clear();
		st.clear();
		for(int i=0;i<N;i++) {
			cin>>cases[i];
			if(cases[i] <= T) st.insert(cases[i]);
		}
		for(int i:st) vec.push_back(i);
		
		if(!vec.empty()) two(0,vec.size()-1);
		
		if(ans.first==0 || ans.first==-1) {
			cout<<0<<" "<<T<<endl;
		} else {
			cout<<ans.first<<" "<<ans.second<<endl;
		}
		//cout<<endl;
	}
	
	return 0;
}

