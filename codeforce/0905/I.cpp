#include<iostream>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
long long int total=0;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> row,column;
int *x[2000000],N,M,Q;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>M>>Q;
	for(int i=1;i<=N;i++) {
		row.insert(i);
		x[i] = new int[M+1];
		for(int j=1;j<=M;j++) {
			cin>>x[i][j];
			total += x[i][j];
		}
	}
	for(int i=1;i<=M;i++) column.insert(i);
	
	for(int i=0;i<Q;i++) {
		int rl,cl,rr,cr;
		cin>>rl>>cl>>rr>>cr;
		rr = min(rr,(int)row.size());
		cr = min(cr,(int)column.size());
		auto it = row.find_by_order(rl-1);
		for(int j=rl;j<=rr;j++) {
			for(int k:column) total -= x[*it][k];
			row.erase(it++);
		}
		it = column.find_by_order(cl-1);
		for(int j=cl;j<=cr;j++) {
			for(int k:row) total -= x[k][*it];
			column.erase(it++);
		}
		
		cout<<total<<'\n';
	}
	
	/*for(int i:row) cout<<i;
	cout<<endl;
	for(int i:column) cout<<i;*/
	
	
	return 0;
} 
