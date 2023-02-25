#include<iostream>
#include<vector>
using namespace std;
vector<int> keep;
int T;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	keep.push_back(1);
	keep.push_back(2);
	int cnt=0,need_add=1,change=2;
	for(int i=0;;i++) {
		if(i==change) {
			change*=2;
			need_add++;
			keep.push_back(cnt+1);
		}
		cnt+=need_add;
		if(1e9 < cnt) break;
	}
	
	//for(int i:keep)cout<<i<<endl;
	//cout<<keep.size();
	
	cin>>T;
	while(T--) {
		int k;
		cin>>k;
		for(int i=keep.size()-1;i>=0;i--) {
			if(keep[i] <= k) {
				cout<<i<<endl;
				break;
			}
		}
	}
	
	return 0;
}
