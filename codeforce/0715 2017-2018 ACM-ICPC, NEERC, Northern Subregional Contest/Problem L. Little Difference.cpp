#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#define pll pair<long long int,long long int>
#define endl "\n"
using namespace std;
vector<pll>vec,same;
map<long long int,int>factor;
long long int n,tt;


void go(long long int x,bool no) {
	for(auto it=factor.begin();it!=factor.end();it++) {
		if(it->second>0) {
			//cout<<it->first<<" "<<it->second<<" "<<x<<endl;
			int tmp=it->second;
			long long int p=it->first;
			it->second=0;
			go(x,true);
			for(int i=0;i<tmp;i++) {
				go(x*p,false);
				p*=it->first;
			}
			it->second=tmp;
			break;
		}
	}
	if(!no&&x!=n) {
		bool y=true;
		int count=0;
		tt=n;
		while(tt!=1&&y) {
			if(tt%x==0) tt/=x;
			else y=false;
			count++;
		}
		if(y) same.push_back(pll(count,x));
		
		if(!y&&tt%(x+1)==0) {
			y=true;
			while(tt!=1&&y) {
				if(tt%(x+1)==0) tt/=(x+1);
				else y=false;
			}
			if(y) vec.push_back(pll(x,x+1));
		}
	}
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	freopen("little.in","r",stdin);    // Åª file.in ÀÉ
	freopen("little.out","w",stdout);  // ¼g¤J file.out ÀÉ
	cin>>n;
	
	tt=n;
	bool oo=false;
	while(tt%2==0) {
		if(tt==2) oo=true;
		tt/=2;
	}
	
	if(n==1||oo) {
		cout<<-1;
	} else {
		long long int t=n;
		for(int i=2;i<=sqrt(t);) {
			if(t%i==0) {
				factor[i]++;
				t/=i;
			} else {
				if(i==2) i++;
				else i+=2;
			}
		}
		if(t!=1) factor[t]++;
		
		//for(auto it=factor.begin();it!=factor.end();it++) cout<<it->first<<" "<<it->second<<endl;
		
		go(1,true);
		
		cout<<same.size()+vec.size()+1<<endl;
		cout<<1<<" "<<n<<endl;
		for(auto it=same.begin();it!=same.end();it++) {
			cout<<it->first;
			for(int i=0;i<it->first;i++) cout<<" "<<it->second;
			cout<<endl;
		}
		for(auto it=vec.begin();it!=vec.end();it++) {
			long long int a=it->first,aa=0,b=it->second,bb=0,tmp;
			tmp=n;
			while(tmp%a==0) {
				aa++;
				tmp/=a;
			}
			tmp=n;
			while(tmp%b==0) {
				bb++;
				tmp/=b;
			}
			cout<<aa+bb;
			for(int i=0;i<aa;i++) {
				cout<<" "<<a;
			}
			for(int i=0;i<bb;i++) {
				cout<<" "<<b;
			}
			cout<<endl;
		}
	}
	
	
	return 0;
} 
