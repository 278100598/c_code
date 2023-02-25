#include<iostream>
#include<map>
#define ff first
#define ss second
using namespace std;
int N,T,arr[40];
map<long long int,long long int> l,r,t;

int main() {
	while(cin>>N>>T) {
		for(int i=0;i<N;i++) cin>>arr[i];
		
		l.clear();
		l[0]=1;
		r.clear();
		r[0]=1;
		
		for(int i=0;i<N/2;i++) {
			t.clear();
			for(auto it:l) t[it.ff+arr[i]]=it.ss;
			for(auto it:t) l[it.ff]+=it.ss;
		}
		for(int i=N/2;i<N;i++) {
			t.clear();
			for(auto it:r) t[it.ff+arr[i]]=it.ss;
			for(auto it:t) r[it.ff]+=it.ss;
		}
		
		long long int ans=0;
		for(auto i:l) {
			auto it=r.find(T-i.ff);
			if(it!=r.end()) ans+=it->ss*i.ss;
		}
		if(T==0) ans-=1;
		cout<<ans<<'\n';
	}
	
	return 0;
}
