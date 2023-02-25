#include<iostream>
#include<algorithm>
#define mp make_pair
using namespace std;
int head=0,tail=0,N;
pair<int,int> tree[(int)4e5];

void add(int t,int index,int l,int r,int num) {
	if(tree[index].first == 0) tree[index] = mp(num,num);
	else tree[index] = mp(__gcd(tree[index].first,num),min(tree[index].second,num));
	if(l==r) return;
	
	int m=(l+r)/2;
	if(t <= m) add(t,(index<<1),l,m,num);
	if(m+1 <= t) add(t,(index<<1)+1,m+1,r,num);
}

pair<int,int> find(int begin,int end,int index,int l,int r) {
	if(begin <= l && r <= end) {
		//cout<<l<<" "<<r<<" "<<tree[index].first<<" "<<tree[index].second<<endl;
		return tree[index];
	}
	
	int m=(l+r)/2;
	pair<int,int> x=mp(-1,-1),y=mp(-1,-1);
	if(begin <= m) x = find(begin,end,(index<<1),l,m);
	if(m+1 <= end) y = find(begin,end,(index<<1)+1,m+1,r);
	
	if(x.first != -1 && y.first != -1) {
		return mp(__gcd(x.first,y.first),min(x.second,y.second));
	}
	else if(x.first != -1) return x;
	else return y;
} 

int main() {
	cin>>N;
	for(int i=0;i<N;i++) {
		char c;
		cin>>c;
		if(c=='+') {
			int x;
			cin>>x;
			add(tail,1,0,1e5,x);
			tail++;
		} else if(c=='-') {
			head++;
		} else if(c=='?') {
			pair<int,int> f = find(head,tail-1,1,0,1e5);
			if(f.first == f.second) cout<<"Y"<<f.first<<'\n';
			else cout<<"N\n";
		}
		
	}
	
}
