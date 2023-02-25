#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
unsigned int MOD = (1LL<<31)-1,mask1 = (1LL<<32) - (1LL<<16),mask2 = (1LL<<16)-1;
unsigned int N,K,A,B,C,pre,prepre,keep[1<<16],front,back;
vector<unsigned int> ans;

int main() {
	cin>>N>>K>>prepre>>pre>>A>>B>>C;
	
	int p=pre,pp=prepre;
	for(int i=0;i<(1<<16);i++) keep[i]=0;
	for(int i=0;i<N;i++) {
		//if(i%1000000 == 0) cout<<i<<endl;
		unsigned int x = (A*pp) + (B*p) + C;
		x &= MOD;
		pp = p;
		p = x;
		
		x = (x & mask1) >> 16;
		keep[x]++;
	}
	int sum=0,tmp;
	for(int i=(1<<16)-1;i>=0;i--) {
		sum += keep[i];
		if(sum >= K) {
			front = i<<16;
			tmp = sum - keep[i];
			break;
		}
	}
	
	p=pre,pp=prepre;
	for(int i=0;i<(1<<16);i++) keep[i]=0;
	for(int i=0;i<N;i++) {
		//if(i%1000000 == 0) cout<<i<<endl;
		unsigned int x = (A*pp) + (B*p) + C;
		x &= MOD;
		pp = p;
		p = x;
		
		if((x & mask1) == front) keep[x & mask2]++;
	}
	sum=tmp;
	for(int i=(1<<16)-1;i>=0;i--) {
		sum += keep[i];
		if(sum >= K) {
			back = i;
			break;
		}
	}
	
	//cout<<front+back;
	p=pre,pp=prepre;
	for(int i=0;i<N;i++) {
		//if(i%1000000 == 0) cout<<i<<endl;
		unsigned int x = (A*pp) + (B*p) + C;
		x &= MOD;
		pp = p;
		p = x;
		
		if(x > front+back) ans.push_back(x);
	}
	sort(ans.rbegin(),ans.rend());
	for(int i:ans) cout<<i<<" ";
	for(int i=ans.size();i<K;i++) cout<<front+back<<" ";
	return 0;
}
/*
100000000 200000
0 0 0 1 1
*/

