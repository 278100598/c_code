#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> p[3];
int main() {
	for(int i=0;i<3;i++) cin>>p[i].first>>p[i].second;
	sort(p,p+3);
	
	int mx=-1e9,mn=1e9;
	for(int i=0;i<3;i++) {
		mx = max(mx,p[i].second);
		mn = min(mn,p[i].second);
	}
	
	cout<<"3\n";
	cout<<p[1].first<<" "<<mn<<" "<<p[1].first<<" "<<mx<<'\n';
	cout<<p[1].first<<" "<<p[0].second<<" "<<p[0].first<<" "<<p[0].second<<'\n';
	cout<<p[1].first<<" "<<p[2].second<<" "<<p[2].first<<" "<<p[2].second<<'\n';
	return 0;
}
