#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,ans=0;
vector<int> people[4];
int main() {
	cin>>N;
	for(int i=0;i<N;i++) {
		int x;
		string s;
		cin>>s>>x;
		if(s=="00") people[0].push_back(x);
		else if(s=="01") people[1].push_back(x);
		else if(s=="10") people[2].push_back(x);
		else if(s=="11") people[3].push_back(x);
	}
	
	int cnt=people[3].size(),sum=people[3].size();
	for(int i:people[3]) ans+=i;
	for(int i=0;i<=2;i++) sort(people[i].begin(),people[i].end());
	while(!people[1].empty() && !people[2].empty()) {
		ans += people[1].back();
		people[1].pop_back();
		ans += people[2].back();
		people[2].pop_back();
		cnt++;
		sum+=2;
	}
	
	people[0].insert(people[0].end(),people[1].begin(),people[1].end());
	people[0].insert(people[0].end(),people[2].begin(),people[2].end());
	sort(people[0].begin(),people[0].end());
	while(sum < cnt*2 && !people[0].empty()) {
		ans+=people[0].back();
		people[0].pop_back();
		sum++;
	}
	cout<<ans;
	return 0;
}
