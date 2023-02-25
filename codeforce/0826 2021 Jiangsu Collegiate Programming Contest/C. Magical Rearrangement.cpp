#include<iostream>
#include<vector>
using namespace std;

int cnt[10],T;

int main() {
	cin>>T;
	while(T--) {
		int total=0,pre=0;
		for(int i=0;i<=9;i++) {
			cin>>cnt[i];
			total+=cnt[i];
		}
		vector<int> ans;
		
		bool y=true,zero=false;
		if(cnt[0]==1) zero=true;
		if(cnt[0] > total-cnt[0]) y=false;
		for(int i=1;i<=9;i++) {
			if(cnt[i] != 0) zero=false;
			if(cnt[i] > total-cnt[i]+1) y=false; 
		}
		if(zero) {
			cout<<0<<endl;
			continue;
		}
		if(!y) {
			cout<<-1<<endl;
			continue;
		}
		
		while(total) {
			int danger=-1;
			for(int i=0;i<=9;i++) {
				if(i == pre) continue;
				if(cnt[i] == total-cnt[i]+1) danger=i;
			}
			//cout<<total<<" "<<ans.size()<<endl;
			if(danger==-1) {
				for(int i=0;i<=9;i++) {
					if(i == pre) continue;
					if(cnt[i] > 0) {
						cnt[i]--;
						ans.push_back(i);
						pre = i;
						break;
					}
				}
			} else {
				cnt[danger]--;
				ans.push_back(danger);
				pre = danger;
			}
			total--;
		}
		
		for(int i:ans) cout<<i;
		cout<<endl;
	}
	
	
	return 0;
}
/*
1
1 0 0 0 0 0 0 0 0 0
*/
